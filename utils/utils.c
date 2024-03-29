#include "utils.h"
#include <stdio.h>



void show_usage() {
    printf("Usage: ./err [OPTION]...\n");
    printf("this is a demo .\n\n");

    printf("  -l  --logs          equivalent to -vET\n");
    printf("  -h    --help        display this help and exit\n");
    printf("  -v    --version     output version information and exit\n\n");
    exit(1);
}


void show_version()
{
    printf("err 0.0.1\n");
    exit(1);
}
