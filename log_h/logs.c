#include "logs.h"

char* get_log_file()
{
    char* buf = malloc(sizeof(char)*BUFSIZE);
    char* timebuf = malloc(sizeof(char)*BUFSIZE);
    
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	strftime(timebuf, BUFSIZE - 4, "%d-%m-%Y", t);

	strcpy(buf, "logs/log_");
	strcat(buf, timebuf);
	strcat(buf, ".logs");
    
    free(timebuf);
    return buf;
}

char* get_time()
{
    char* timebuf = malloc(sizeof(char)*BUFSIZE);
    
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	strftime(timebuf, BUFSIZE - 4, "%d-%m-%Y_%H:%M:%S", t);

    return timebuf;
}


log log_init()
{
    log l = malloc(sizeof(struct log_s));

    if(l == NULL){
        perror("log_init:malloc");
        exit(1);
    }

    l->path = get_log_file();

    int fd = open(l->path, O_RDWR | O_CREAT, 0777);
    if(-1 == fd){
        perror("log_init:malloc");
        exit(1);
    }

    l->fd = fd;

    l->f = fdopen(l->fd, "a");
    if (l->f == NULL) { 
        perror("log_init: fdopen");
        exit(1);
    }

    return l;
}

char* getlog_type(enum log_type lt)
{
    switch (lt) {
        case INFO:
            return "INFO";
            break;
        case ERROR:
            return "ERROR";
            break;
        case LOG:
            return "LOG";
            break;
        case FATAL:
            return "FATAL";
            break;
    }
    return "UNKNOWN";
}

void printl(log l, enum log_type lt, const char *file, int line, const char* func, const char *format, ...) 
{
    if (l == NULL || l->fd == -1 || l->f == NULL) {
        fprintf(stderr, "Invalid log structure or file descriptor.\n");
        return;
    }

    char *buf = malloc(sizeof(char) * BUFSIZE);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    snprintf(buf, BUFSIZE, "[%s] [%s] [%s:%d] [%s] > %s\n", get_time(), getlog_type(lt), file, line, func, format);

    va_list args;
    va_start(args, format);

    vfprintf(l->f, buf, args);

    va_end(args);

    fflush(l->f);

    free(buf);
}

void logFunctionCall(log l, enum log_type lt, const char *file, int line, const char* func) 
{
    if (l == NULL || l->fd == -1 || l->f == NULL) {
        fprintf(stderr, "Invalid log structure or file descriptor.\n");
        return;
    }

    char *buf = malloc(sizeof(char) * BUFSIZE);
    if (buf == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    snprintf(
        buf, BUFSIZE, "[%s] [%s] [%s:%d] call: %s()\n",
        get_time(), getlog_type(lt), file, line, func
    );

    fprintf(l->f, "%s", buf);

    fflush(l->f);

    free(buf);
}

void sepatator(log l)
{
    FLOG(l);
    fprintf(l->f, "\t\t\t\t\t\t\t\t\t\t\t--------------\n");
}

void log_destroy(log* l) 
{
    FLOG(*l);
    if (l == NULL || *l == NULL) {
        return;
    }

    LOG(*l,LOG, "free'd path and closed stream");
    sepatator(*l);
    if ((*l)->path != NULL) {
        free((*l)->path);
        (*l)->path = NULL;
    }

    fclose((*l)->f);

    free(*l);
    *l = NULL;
}

