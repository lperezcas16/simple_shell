#include "0_principal_header.h"

/**
 * help_function - Implementation of built-in command help
 *
 * @vars: Variable containing the commands
 *
 * Return: 0 (Success) Otherwise 1 (Error)
 */
int help_function(var_s *vars)
{
	int i = 0;

	help help_list[] = {
		{"exit", help_exit},
		{"env", help_env},
		{"setenv", help_setenv},
		{"unsetenv", help_unsetenv},
		{"help", help_help},
		{NULL, NULL}
	};

	char *value;

	value = vars->tokens[1];
	vars->status = 0;

	if (value == NULL || value[0] == '\0')
	{
		print_help();
		return (0);
	}
	while (help_list[i].fc)
	{
		if (_strcmp(vars->tokens[1], help_list[i].fc) == 0)
		{
			help_list[i].f();
			return (0);
		}
		i++;
	}
	return (1);
}
