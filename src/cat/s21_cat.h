#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include "../common/utils.h"

typedef struct cat_arguments {
    bool b;
    bool e;
    bool E;
    bool n;
    bool s;
    bool t;
    bool T;
    bool v;
    char *file_paths[50];
    int files_num;
} cat_arguments;

cat_arguments get_cat_arguments(int argc, char **argv);

void print_file(char *filename, cat_arguments args);

void print_error_cat();

#endif  //  SRC_CAT_S21_CAT_H_
