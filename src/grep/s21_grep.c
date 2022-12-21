#include "s21_grep.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_error_grep();
    } else {
        char *expressions[CAPACITY];
        for (int i = 0; i < CAPACITY; i++) {
            expressions[i] = NULL;
        }
        grep_arguments args = get_grep_arguments(argc, argv, expressions);
        for (int i = 0; i < args.files_num; i++) {
            if (file_exists(args.file_paths[i], s21_GREP, args.s)) {
                print_grep(args, i, expressions);
            }
        }
        for (int i = 0; i < CAPACITY; i++) {
            if (expressions[i] != NULL) free(expressions[i]);
        }
    }
    return 0;
}
