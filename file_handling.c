#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }
    fprintf(fp, "This is the initial content of the file.\n");
    fclose(fp);
    printf("File created successfully.\n");
}

void readFile(const char *filename) {
    char ch;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error reading file");
        return;
    }
    printf("Reading file content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error writing to file");
        return;
    }
    fprintf(fp, "File content overwritten.\nThis is the new content.\n");
    fclose(fp);
    printf("Data written successfully.\n");
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error appending to file");
        return;
    }
    fprintf(fp, "This is appended content.\n");
    fclose(fp);
    printf("Data appended successfully.\n");
}

int main() {
    const char *filename = "example.txt";

    createFile(filename);
    readFile(filename);

    writeFile(filename);
    readFile(filename);

    appendFile(filename);
    readFile(filename);

    return 0;
}
