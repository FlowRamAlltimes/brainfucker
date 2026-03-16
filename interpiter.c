#include <stdio.h>
#include <string.h>

int main() {
    char str[4096] = {0};
  
    printf("Put your brainfuck code here:\n");
  
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
  
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
