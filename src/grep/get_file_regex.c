#include "s21_grep.h"

grep_arguments get_expression(char *path, grep_arguments args, char **expressions) {
    size_t exp_length = 0;
    FILE *file = fopen(path, "r");
    if (file != NULL) {
        char *ready_expression = NULL;
        char line[LENGTH] = "\0";
        int c = 0;
        while ((c = getline(&ready_expression, &exp_length, file)) != -1) {
            strncpy(line, ready_expression, strlen(ready_expression));
            for (size_t i = 0; i < strlen(line); i++) {
                if (line[i] == '\n') line[i] = '\0';
            }
            expressions[args.exp_count] = malloc(strlen(line) * sizeof(char)+1);
            strncpy(expressions[args.exp_count], line, strlen(line));
            expressions[args.exp_count][strlen(line)] = '\0';
            args.exp_count++;
        }
        free(ready_expression);
        fclose(file);
    } else {
        fprintf(stderr, "s21_grep: %s: No such file or directory\n", path);
        args.exp_count = 0;
    }
    return args;
}
