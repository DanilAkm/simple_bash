#include "s21_cat.h"

int main(int argc, char **argv) {
    if (argc >= 2) {
        cat_arguments arguments = get_cat_arguments(argc, argv);
        for (int i = 0; i < arguments.files_num; i++) {
            if (file_exists(arguments.file_paths[i], s21_CAT, false)) {
                print_file(arguments.file_paths[i], arguments);
            }
        }
    } else {
        print_error_cat(argv);
    }
    return 0;
}
