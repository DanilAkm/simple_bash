#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include "../common/utils.h"
#include <regex.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY            50
#define LENGTH              100
#define MAX_MATCHES         100

typedef struct grep_arguments {
    bool i;
    bool v;
    bool c;
    bool l;
    bool n;
    bool h;
    bool s;
    bool o;
    bool good_to_go;
    char *file_paths[CAPACITY];
    int files_num;
    int exp_count;
} grep_arguments;

grep_arguments get_grep_arguments(int argc, char **argv, char **expressions);
grep_arguments get_expression(char *path, grep_arguments args, char **expressions);
bool find_match(grep_arguments args, char *line, char **expressions);
bool check_f_e(int argc, char **argv);
void struct_to_zero(grep_arguments *args);
void print_grep(grep_arguments arguments, int index, char **expressions);
void print_error_grep();
void l_flag(grep_arguments args, int index, int matches);
void o_flag(grep_arguments args, char *line, char **expressions);
void line_has_break(const char *line);

#endif  //  SRC_GREP_S21_GREP_H_
