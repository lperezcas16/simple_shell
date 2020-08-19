#ifndef HELP_H
#define HELP_H

#include "0_principal_header.h"

/**
 * struct help - Structure for the help function
 *
 * @fc: Finds a command
 *
 * @f: Pointer of the funcion
 */
typedef struct help
{
	char *fc;
	void (*f)();
} help;

int help_function(var_s *vars);
void print_help(void);
void help_exit(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_help(void);

#endif
