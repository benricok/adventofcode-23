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
            char last = '0';
            short first = 0;
            short hasfirst = 0;

            for (int i = 0; i < read; i++) {
                if(48 <= line[i] && line[i] <= 57 ) {
                    last = line[i];
                    printf("%c ", last);
                    if (!hasfirst++) {
                        first = 10 * (line[i] - 0x30);
                    }
                }
            }
            short value = first + last - 0x30;
            printf("\nExstracted value: %d\n\n", value);
            total += value;
        }
        printf("\n\nTotal is %d\n", total);
        fclose(file);
    } else {
        printf("ERROR: No file!!");
    }
    return 0;
}