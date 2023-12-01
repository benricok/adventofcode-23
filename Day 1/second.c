#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char* str;
    size_t len;
    char n;
};

struct entry dict[] = {
    "zero", 4, '1',
    "one", 3, '1',
    "two", 3, '2',
    "three", 5, '3',
    "four", 4, '4',
    "five", 4, '5',
    "six", 3, '6',
    "seven", 5, '7',
    "eight", 5, '8',
    "nine", 4, '9',
};


int main () {
    unsigned long total = 0;
    char * line = malloc(sizeof line * 100);
    size_t buflen = 100;
    size_t len = 0;

    FILE * file = fopen("input.txt", "r");
    if (file) {
        while ((len = getline(&line, &buflen, file)) != -1) {
            printf("%s", line);
            printf("length: %d\n", len);
            char last = '0', first = '0';
            short hasfirst = 0;

            char buff[5] = "00000";
            size_t bufflen = 0;

            for (int i = 0; i < len; i++) {
                printf("Buffer: ");
                for (size_t g = 0; g < 5; g++) {
                    printf("%c", buff[g]);
                }
                printf("\n");

                if ('0' <= line[i] && line[i] <= '9') {
                    last = line[i];
                    printf("Last: %c\n", last);
                    if (!hasfirst++) {
                        first = line[i];  
                    }
                    bufflen = 0;

                } else if ('a' <= line[i] && line[i] <= 'z') {

                    if (bufflen < 5) {
                        buff[bufflen++] = line[i];
                    } else {
                        for (size_t k = 0; k < 4; k++) {
                            buff[k] = buff[k+1];
                        }
                        buff[4] = line[i];
                    }

                    for (size_t j = 0; j < 10; j++) {
                        char buff1[4] = "0000";
                        char buff2[3] = "000";
                        strncpy(buff1, buff+1, 4);
                        strncpy(buff2, buff+2, 3);
                        if (strncmp(dict[j].str, buff, dict[j].len) == 0 ||
                            strncmp(dict[j].str, buff1, dict[j].len) == 0 ||
                            strncmp(dict[j].str, buff2, dict[j].len) == 0) {
                    
                            last = dict[j].n;
                            printf("Last: %c\n", last);
                            if (!hasfirst++) {
                                first = dict[j].n;  
                            }
                            bufflen = 0;
                            strcpy(buff, "00000");
                            break;
                        }
                    } 
                } 
            }
            char val[] = "00"; 
            val[0] = first;
            val[1] = last;
            short value = atoi(val);
            printf("\nExstracted value: %d\n\n", value);
            total += value;
        }
        free(line);
        printf("\n\nTotal is %d\n", total);
    } else {
        printf("ERROR: No file!!");
    }
    return 0;
}