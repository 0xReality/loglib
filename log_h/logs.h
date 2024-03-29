#ifndef LOGS_H
#define LOGS_H

#include <string.h>    /* strcpy, strcat, strlen */
#include <stdio.h>     /* fprintf, snprintf, va_start, va_end, vfprintf, perror, fdopen */
#include <stdlib.h>    /* malloc, free, exit */
#include <time.h>      /* time, localtime, strftime */
#include <fcntl.h>     /* open */
#include <stdarg.h>    /* va_list, va_start, va_end */


#define BUFSIZE 1024

#define LOG(l, lt, format, ...) printl(l, lt, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define FLOG(l) log_function_call(l, LOG, __FILE__, __LINE__, __func__)

enum log_type{
    INFO = 0,
    ERROR = 1,
    LOG = 2,
    FATAL = 3
};

typedef struct log_s{
    char* path;
    FILE* f;
}* log;

/* 
 * Renvoie le nom du fichier log.
 * 
 * @return char*  Pointeur vers le nom du fichier log.
*/
char* get_log_file();

/* 
 * Renvoie la date et l'heure actuelles au format dd-mm-yy_hh-mm-ss.
 * 
 * @return char*  Pointeur vers la chaîne de caractères représentant la date et l'heure.
*/
char* get_time();

/* 
 * Initialise le système de journalisation et renvoie un pointeur vers la structure de journalisation initialisée.
 * 
 * @return log  Pointeur vers la structure de journalisation après initialisation.
*/
log log_init();

/* 
 * Renvoie le type de log à afficher en fonction du type de log fourni.
 * 
 * @param lt  Type de log (enum log_type).
 * @return char*  Pointeur vers la chaîne de caractères représentant le type de log.
*/
char* get_log_type(enum log_type lt);


/* 
 * Écrit un message de log formaté.
 * 
 * @param l       Pointeur vers la structure de log.
 * @param lt      Type du zmessage de log (log_t).
 * @param file    Nom du fichier source.
 * @param line    Numéro de la ligne dans le fichier source.
 * @param func    Nom de la fonction appelante.
 * @param format  Format du message suivant la syntaxe de printf.
*/

void printl(log l, enum log_type lt, const char *file, int line, const char* func, const char *format, ...);


/* 
 *  log l'appel de fonction.
 * 
 * Paramètres:
 *   @param l    Pointeur vers la structure de log.
 *   @param lt   Type du message de log (enum log_type).
 *   @param file Nom du fichier source.
 *   @param line Numéro de la ligne dans le fichier source.
 *   @param func Nom de la fonction appelante.
*/
void log_function_call(log l, enum log_type lt, const char *file, int line, const char* func);

/* 
 *  marque la fin du programme
 * 
 * Paramètres:
 *   @param l    Pointeur vers la structure de log.
*/
void sepatator(log l);


/* 
 * Libère la mémoire et ferme les ressources associées à l'instance de log.
 * 
 * Paramètre:
 *   @param l adresse du pointeur de la structure de log.
*/
void log_destroy(log* l);


#endif //LOGS_H
