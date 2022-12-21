#include "s21_cat.h"

void print_file(char *filename, cat_arguments args) {
    FILE *fptr = fopen(filename, "r");
    int count = 1;
    int c = fgetc(fptr);
    int d = fgetc(fptr);
    bool first = true;

    while (true) {
        while (args.s && c == '\n' && d == '\n') {
            char e = fgetc(fptr);
            if (e != '\n') {
                fseek(fptr, -1, SEEK_CUR);
                if (first) d = fgetc(fptr);
                break;
            }
        }
        if (args.b && first && c != '\n') printf("%6d\t", count++);
        if (args.n && first) printf("%6d\t", count++);
        if (args.E && c == '\n') printf("$");

        if (args.v && ((c >= 0 && c <= 31) || c == 127) && c != '\n' && c != '\t') {
            if (c == 127) {
                printf("^?");
            } else {
                printf("^%c", c + 64);
            }
        } else if (args.t && ((c >= 0 && c <= 31) || c == 127) && c != '\n') {
            if (c == 127) {
                printf("^?");
            } else {
                printf("^%c", c + 64);
            }
        } else if (args.T && c == '\t') {
            printf("^I");
        } else {
            printf("%c", c);
        }

        if (args.n && c == '\n' && d != EOF) printf("%6d\t", count++);
        if (args.b && c == '\n' && d != '\n' && d != EOF) printf("%6d\t", count++);
        c = d;
        d = fgetc(fptr);
        first = false;
        if (c == EOF) break;
    }
    fclose(fptr);
}
