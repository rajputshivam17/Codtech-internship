#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress using RLE
void compressRLE(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        return;
    }

    char prev = fgetc(in);
    int count = 1;
    char curr;

    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }
    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);
    printf("Compression completed.\n");
}

// Function to decompress RLE
void decompressRLE(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    int count;

    while (fscanf(in, "%c%d", &ch, &count) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("Decompression completed.\n");
}

int main() {
    // Create a sample input file
    FILE *sample = fopen("input.txt", "w");
    fprintf(sample, "aaabbbccccddddd");
    fclose(sample);

    compressRLE("input.txt", "compressed.txt");
    decompressRLE("compressed.txt", "decompressed.txt");

    return 0;
}
