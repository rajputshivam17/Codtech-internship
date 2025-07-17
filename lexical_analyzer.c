#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char keywords[10][10] = { "int", "float", "char", "if", "else", "while", "for", "return", "void", "main" };

// Function to check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to perform lexical analysis
void lexicalAnalyzer(const char *filename) {
    FILE *fp;
    char ch, buffer[100];
    int i, j = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else {
            if (j != 0) {
                buffer[j] = '\0';
                j = 0;
                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);
            }
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
                printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
}

int main() {
    // Create a sample input file
    FILE *sample = fopen("input.txt", "w");
    fprintf(sample, "int main() { int a = b + 5; return a; }");
    fclose(sample);

    // Perform lexical analysis on the sample input
    printf("Lexical Analysis Output:\n");
    lexicalAnalyzer("input.txt");

    return 0;
}
