#include "err_h/err.h" /* init_err_mess, get_err_mess */
#include "log_h/logs.h" /* log_init, LOG */


int main(int argc, char **argv) 
{
  log l = log_init();
  initialize_error_messages();
  
  if (argc < 2) {
    LOG(l, FATAL, get_err_mess(INSUFF_ARGS, l));
    log_destroy(&l);
    destroy_err_mess();
    return 1; 
  }else if(argc > 2){
    LOG(l, FATAL, get_err_mess(TOOMUCH_ARGS, l));
    log_destroy(&l);
    destroy_err_mess();
    return 1;
  }

  LOG(l, INFO, "completed all argument tests");
  log_destroy(&l);
  destroy_err_mess();
  return 0;
}
