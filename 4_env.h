#ifndef ENV_H
#define ENV_H

#include "0_principal_header.h"

/* ----------------------------*/
/*-------- Prototypes--------- */
/* ----------------------------*/
token_s *_start_env(void);
char *_getenv(char *name, var_s *vars);
int PrintEnviroment(var_s *vars);
int _setenv(var_s *vars);
int _unsetenv(var_s *vars);

#endif
