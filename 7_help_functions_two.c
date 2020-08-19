#include "0_principal_header.h"

/**
 * help_env - Shows information about built-in command "env".
 *
 */
void help_env(void)
{
	_puts("env: env\n");
	_puts("\tPrints the current environment.\n");
}

/**
 * help_setenv - Shows information about built-in command "setenv".
 *
 */
void help_setenv(void)
{
	_puts("setenv: setenv [VARIABLE]\n");
	_puts("\tInitializes a new environment variable,\n");
	_puts("\tor modifies an existing one.\n\n");
	_puts("\tIf it fails, prints a message to stderr.\n");
}

/**
 * help_unsetenv - Shows information about built-in command "unsetenv".
 *
 */
void help_unsetenv(void)
{
	_puts("unsetenv: unsetenv [VARIABLE]\n");
	_puts("\tRemoves an environment variable.\n\n");
	_puts("\tIf it fails, prints a message to stderr.\n");
}
