#include "s21_grep.h"

void print_grep(grep_arguments args, int index, char **expressions) {
    FILE *file = fopen(args.file_paths[index], "r");
    size_t line_length = 0;
    char *line = NULL;
    int count_matches = 0;
    int count_lines = 0;

    while ((getline(&line, &line_length, file) != -1) && args.good_to_go) {
    bool found = false;
        count_lines++;
        found = find_match(args, line, expressions);
        if (found) {
            count_matches++;
            if (!args.c && !args.l) {
                if (args.files_num > 1) {
                    if (!args.h) printf("%s:", args.file_paths[index]);
                    if (args.n) printf("%d:", count_lines);
                    printf("%s", line);
                    line_has_break(line);
                } else {
                    if (args.n) printf("%d:", count_lines);
                    printf("%s", line);
                    line_has_break(line);
                }
            }
        }
    }
    printf("%s", line);
    if (args.c && !args.l) {
        if (!args.h) {
            if (args.files_num > 1) printf("%s:%d\n", args.file_paths[index], count_matches);
            if (args.files_num == 1) printf("%d\n", count_matches);
        } else {
            printf("%d\n", count_matches);
        }
    }
    if (args.l) l_flag(args, index, count_matches);
    if (line != NULL) free(line);
    fclose(file);
}

bool find_match(grep_arguments args, char *line, char **expressions) {
    bool found = false;
    regex_t regex;
    int comp_flag = 0;

    if (args.i) {
        comp_flag = REG_ICASE;
    } else {
        comp_flag = REG_EXTENDED;
    }

    for (int i = 0; i < args.exp_count; i++) {
    int match = 0;

        match = regcomp(&regex, expressions[i], comp_flag);

        if (match) {
            fprintf(stderr, "an error occured while compiling the expression");
            break;
        }

        match = regexec(&regex, line, 0, NULL, 0);
        regfree(&regex);
        if (!match) {
            found = true;
            break;
        }
    }
    if (args.v) found = !found;
    return found;
}

void l_flag(grep_arguments args, int index, int matches) {
    if (args.files_num > 1) {
        if (matches == 0 && args.c) {
            if (!args.h) printf("%s", args.file_paths[index]);
            if (!args.h && args.c) printf(":");
            if (args.c) printf("0\n");
        } else {
            if (args.c && !args.h) printf("%s", args.file_paths[index]);
            if (!args.c && !args.h && matches > 0) printf("%s\n", args.file_paths[index]);
            if (args.h && matches > 0 && !args.c) printf("%s\n", args.file_paths[index]);
            if (!args.h && args.c) printf(":");
            if (args.c) printf("1\n%s", args.file_paths[index]);
            if (args.c) printf("\n");
        }
    } else {
        if (matches > 0) {
            if (args.c) printf("1\n");
            printf("%s\n", args.file_paths[index]);
        } else {
            if (args.c) printf("0\n");
        }
    }
}

void line_has_break(const char *line) {
    size_t len = strlen(line);
    bool isbreak = ('\n' == line[len-1]);
    if(!isbreak) printf("\n");
}