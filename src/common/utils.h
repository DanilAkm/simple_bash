#ifndef SRC_COMMON_UTILS_H_
#define SRC_COMMON_UTILS_H_

#define _GNU_SOURCE

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>

#define short_cat_args "beEnstTv"
#define grep_args "-:e:ivclnhsf:o"

#define s21_GREP "s21_grep"
#define s21_CAT "s21_cat"

bool file_exists(char *filepath, char *util_str, bool suppress);

#endif  //  SRC_COMMON_UTILS_H_
