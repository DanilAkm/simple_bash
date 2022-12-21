#include "s21_grep.h"

int opt;
int option_index;
int file_exp_suc = 0;
char *first_arg;
grep_arguments fields;

void clean_paths(char **paths) {
    for (int i = 0; i < CAPACITY; i++) {
        paths[i] = NULL;
    }
}

grep_arguments get_grep_arguments(int argc, char **argv, char *expressions[CAPACITY]) {
    struct_to_zero(&fields);
    clean_paths(fields.file_paths);
    fields.good_to_go = true;
    fields.exp_count = 0;
    while ((opt = getopt_long(argc, argv, grep_args, NULL, NULL)) != -1) {
        switch (opt) {
            case 'v': fields.v = true; break;
            case 'i': fields.i = true; break;
            case 'c': fields.c = true; break;
            case 'l': fields.l = true; break;
            case 'n': fields.n = true; break;
            case 's': fields.s = true; break;
            case 'h': fields.h = true; break;
            case 'o': fields.o = true; break;
            case 'e':
                expressions[fields.exp_count] = malloc(strlen(optarg) * sizeof(char)+1);
                strncpy(expressions[fields.exp_count], optarg, strlen(optarg));
                expressions[fields.exp_count++][strlen(optarg)] = '\0';
                break;
            case 'f':
                fields = get_expression(optarg, fields, expressions);
                break;
            case ':':
                fprintf(stderr, "%s: option requires an argument -- %c\n", argv[0], optopt);
                print_error_grep();
                break;
            case '\1':
                if (fields.exp_count == 0 && !check_f_e(argc, argv)) {
                    expressions[fields.exp_count] = malloc(strlen(optarg) * sizeof(char)+1);
                    strncpy(expressions[fields.exp_count], optarg, strlen(optarg));
                    expressions[fields.exp_count++][strlen(optarg)] = '\0';
                } else {
                    fields.file_paths[fields.files_num++] = optarg;
                }
                break;
            case '?':
                fprintf(stderr, "Invalid option -- %c\n", optopt);
        }
    }
    if (fields.l || fields.c || fields.v) fields.o = false;
    return fields;
}

void print_error_grep() {
    fprintf(stderr, "Usage: ./s21_grep [-ivoscnlh] [-f file] [-e pattern] [pattern] [file...]\n");
    exit(EXIT_FAILURE);
}

bool check_f_e(int argc, char **argv) {
    bool found = false;
    for (int i = 0; i < argc; i++) {
        if (strncmp(argv[i], "-f", 2) == 0 || strncmp(argv[i], "-e", 2) == 0) found = true;
    }
    return found;
}

void struct_to_zero(grep_arguments *args) {
    args->c = false;
    args->exp_count = 0;
    args->files_num = 0;
    args->good_to_go = false;
    args->h = false;
    args->i = false;
    args->l = false;
    args->n = false;
    args->o = false;
    args->s = false;
    args->v = false;
}
