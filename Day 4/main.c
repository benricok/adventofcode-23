#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    size_t len = 0, buflen = 100;
    char* line = malloc(sizeof line * 100);
    unsigned long points = 0;
    int count = 0;

    FILE* file = fopen("input.txt", "r");

    if (file) {
        while((len = getline(&line, &buflen, file)) != -1 && count < 1000) {
            char winNum[29] = "";
            char Num[74] = "";
            strncpy(winNum, line+10, 29);
            strncpy(Num, line+42, 74);

            unsigned short cardpoints = 0;
            
            printf("%s", winNum);
            printf(" | %s\n", Num);

            for (size_t i = 0; i < 25; i++) {
                for (size_t j = 0; j < 10; j++) {
                    //printf("Comparing %c%c and %c%c\n", Num[i*3], Num[i*3 + 1], winNum[j*3], winNum[j*3 + 1]);
                    if (!memcmp(Num + i*3, winNum + j*3, 2)) {
                        //printf("TRUE!\n");
                        if (cardpoints == 0) {
                            cardpoints++;
                        } else {
                            cardpoints *= 2;
                        }
                    }
                }
            }
            printf("Card %d points: %u\n", ++count, cardpoints);
            points += cardpoints;
            }
        printf("\n\nPoints: %lu", points);
    } else {
        printf("ERR: File not found!");
    }
    return 0;
}
