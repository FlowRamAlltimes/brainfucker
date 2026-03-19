#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main() {
    char str[16001] = {0};
    char filename[256];
    printf("Put your file with .bf here:\n");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Interpriter: !Error:\n");
        printf("Your file doesn't exist!\n");
        return 1;
    }
    size_t bytes = fread(str, 1,sizeof(str) - 1, f);
    str[bytes] = '\0';
    fclose(f); // do not forget to close file
    // we have got file data
    char tube[30000] = {0};
    int db = 0;
    int index = 0;
    while (str[index] != '\0') {
        switch (str[index]) {
            case '+':
            tube[db]++;
            break;
            case '-':
            tube[db]--;
            break;
            case '>':
            db++;
            break;
            case '<':
            db--;
            break;
            break;
            case '.':
            putchar(tube[db]);
            break;
            case ',':
            tube[db] = getchar();
            break;
            case ']':
            if (tube[db] != 0) {
                int depth = 1;
                while (depth > 0) {
                    index--;
                    if (str[index] == '[') depth--;
                    if (str[index] == ']') depth++;
                    if (str[index] == '\0') {
                        printf("Interpriter: !Error:\n");
                        printf("There is no closing brecket!\n");
                        return 1;
                    }
                }
            }
            break;
            case '[':
            if (tube[db] == 0) {
                int depth = 1;
                while (depth > 0) {
                    index++;
                    if (str[index] == ']') depth--;
                    if (str[index] == '[') depth++;

                }
            }
            break;
        }
        index++;
    }
    return 0;
}
