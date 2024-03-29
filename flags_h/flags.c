#include "flags.h"


int is_valid_flag(char* arg) {
    const char *valid_flags[] = {"-l", "--logs", "-h", "--help", "-v", "--version"};
    int n = sizeof(valid_flags) / sizeof(valid_flags[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(arg, valid_flags[i]) == 0) {
            return 1; 
        }
    }
    return 0; 
}

void parse_arguments(int argc, char** argv, log l) {
    for (int i = 1; i < argc; i++) {
        if (is_valid_flag(argv[i])) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
                show_usage();
            } else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--logs") == 0) {
                l->stdout_log = 1;
                printf("set value to 1\n");
            }else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version")){
                show_version();
            }
        } else {
            printf("Invalid argument: %s\n", argv[i]);
            show_usage();
            exit(i);
        }
    }
}


