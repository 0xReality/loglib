#ifndef ERR_H
#define ERR_H

#include <stdio.h>     /* fprintf, perror, fdopen */
#include <stdlib.h>    /* malloc, free, exit */
#include <string.h>    /* strcpy, strcat , strlen  */

#include "../log_h/logs.h"

typedef enum {
  OK = 0,
  INSUFF_ARGS,
  TOOMUCH_ARGS,
  INCORR_ARGS,
  ERR_COUNT 
} ErrorCode;

// Initialise le tableau de messages d'erreur.
void initialize_error_messages();

/* Renvoie le message d'erreur correspondant au code d'erreur donné.
* 
* @param code  Le code d'erreur pour lequel obtenir le message.
* @param @param l    Pointeur vers la structure de log.
* @return const char*  Pointeur vers le message d'erreur correspondant.
*/    
const char* get_err_mess(ErrorCode code, log l);


// detruit le err_mes 
void destroy_err_mess();

#endif // ERR_H
