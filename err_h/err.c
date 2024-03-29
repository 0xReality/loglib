#include "err.h"

const char* error_messages[ERR_COUNT];

log l;

void initialize_error_messages() 
{
  
  l = log_init();
  FLOG(l);
  error_messages[OK] = "OK";
  error_messages[INSUFF_ARGS] = "arguments insuffisants";
  error_messages[TOOMUCH_ARGS] = "arguments en plus";
  error_messages[INCORR_ARGS] = "arguments incorrects";
}

const char* get_err_mess(ErrorCode code, log l) 
{
  FLOG(l);
  if (code >= 0 && code < ERR_COUNT) {
    return error_messages[code];
  }
  return "Unknown error code";
}

void destroy_err_mess()
{
  log_destroy(&l);
}
