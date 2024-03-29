#ifndef FLAGS_H
#define FLAGS_H

#include <stdlib.h>

#include "../log_h/logs.h"
#include "../utils/utils.h"

typedef enum flag_e{
    help,
    logs,
}flags;

int is_valid_flag(char* arg);

void parse_arguments(int argc, char** argv, log l);

#endif //FLAGS_H