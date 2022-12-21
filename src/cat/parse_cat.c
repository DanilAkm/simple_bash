#include "s21_cat.h"

int opt;
int option_index;

const struct option gnu_cat_options[] = {
    {"number-nonblank", 0, NULL, 'b'},
    {"number", 0, NULL, 'n'},
    {"squeeze-blank", 0, NULL, 's'},
};

cat_arguments fields;

cat_arguments get_cat_arguments(int argc, char **argv) {
    while ((opt = getopt_long(argc, argv, short_cat_args, gnu_cat_options, &option_index)) != -1) {
        switch (opt) {
            case 'b': fields.b = true;
                break;
            case 'e': fields.E = true; fields.v = true;
                break;
            case 'n': fields.n = true;
                break;
            case 's': fields.s = true;
                break;
            case 't': fields.t = true;
                break;
            case 'E': fields.E = true;
                break;
            case 'T': fields.T = true;
                break;
            case 'v': fields.v = true;
                break;
            default:
                print_error_cat(argv);
        }
    }

    if (fields.b) fields.n = false;

    int i = 0;
    for (; optind < argc; optind++, i++) fields.file_paths[i] = argv[optind];
    fields.files_num = i;
    return fields;
}

void print_error_cat() {
    fprintf(stderr, "Usage: ./s21_cat [-beEnstT --number-nonblank --squeeze-blank] [file...]\n");
    exit(EXIT_FAILURE);
}
