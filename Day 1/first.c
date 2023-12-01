#include <stdio.h>
#include <stdlib.h>

int main () {
    unsigned long total = 0;
    char * line = malloc(sizeof line * 100);
    size_t read;
    size_t buflen = 100;

    FILE * file = fopen("input.txt", "r");
    if (file) {
        while ((read = getline(&line, &buflen, file)) != -1) {
            printf("%s", line);
            printf("length: %d\n", read);
            char last = '0', first = '0';
            short hasfirst = 0;

            for (int i = 0; i < read; i++) {
                if(48 <= line[i] && line[i] <= 57 ) {
                    last = line[i];
                    printf("%c ", last);
                    if (!hasfirst++) 
                        first = line[i];  
                }
            }
            char val[] = "00"; 
            val[0] = first;
            val[1] = last;
            short value = atoi(val);
            printf("Exstracted value: %d\n\n", value);
            total += value;
        }
        printf("\n\nTotal is %d\n", total);
    } else {
        printf("ERROR: No file!!");
    }
    return 0;
}