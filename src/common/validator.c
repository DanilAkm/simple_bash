#include "utils.h"

bool file_exists(char *filepath, char *util_str, bool suppress) {
    FILE *check = NULL;
    DIR *check_dir = NULL;
    bool exists = true;

    check = fopen(filepath, "r");
    if (check == NULL) {
        exists = false;
        if (!suppress) printf("%s: %s: No such file or directory\n", util_str, filepath);
    }

    check_dir = opendir(filepath);
    if (check_dir != NULL) {
        exists = false;
        if (!suppress) printf("%s: %s: Is a directory\n", util_str, filepath);
        closedir(check_dir);
    }

    if (check != NULL) fclose(check);

    return exists;
}
