#include "0_principal_header.h"

/**
 * built_in - Check built in functions
 * @name: Built in name
 * Return: Pointer to function, -1 if fails
 */
int (*built_in(char *name))(var_s *)
{
	find_command_t findc[] = {
		{"exit", ExitFunc},
		{"env", PrintEnviroment},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"help", help_function},
		{NULL, _returnminusone}
	};
	int i = 0;

	while (i < 5)
	{
		if (_strcmp(findc[i].fc, name) == 0)
			break;
		i++;
	}

	return (findc[i].f);
}

/**
 * _returnminusone - Returns minus one
 * @vars: General variables
 * Return: Returns -1;
 */
int _returnminusone(var_s *vars)
{
	(void) vars;

	return (-1);
}

/**
 * ExitFunc - Exit shell
 * @vars: General variables
 * Return: Returns -1 if failed;
 */
int ExitFunc(var_s *vars)
{
	char *cn = vars->tokens[1];
	/* maximum number is 2147483647 */
	unsigned long int tmp = 0, max_i = INT_MAX;
	int i, num;

	if (vars->tokens[0] && vars->tokens[1] == NULL)
	{
		free(vars->tokens);
		free_list(&vars->env);
		free(vars->buffer);
		exit(vars->status);
	}
	else
	{
		for (i = 0; cn[i]; i++)
		{
			if (cn[i] == '-' || (cn[i] < '0' || cn[i] > '9'))
			{
				vars->status = 7;
				return (0);
			}
			tmp = (tmp * 10) + (cn[i] - '0');
			if (tmp > max_i)
			{
				vars->status = 7;
				return (0);
			}
		}
		num = tmp;
		if (num >= 0 && num <= INT_MAX)
		{
			num = num & 255;
			free(vars->tokens);
			free_list(&vars->env);
			free(vars->buffer);
			exit(num);
		}
	}
	vars->status = 7;
	return (0);
}

/**
 * _envtoarray - Converts linke list to double pointer
 * @vars: General variables
 * Return: Returns -1 if failed;
 */
char **_envtoarray(var_s *vars)
{
	char **res;
	int i;
	token_s *tmp = vars->env;

	for (i = 0; tmp; i++)
		tmp = tmp->next;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	tmp = vars->env;
	for (i = 0; tmp; i++)
	{
		res[i] = tmp->str;
		tmp = tmp->next;
	}
	res[i] = NULL;

	return (res);
}
