#include "0_principal_header.h"

/**
 * _printenv - Save enviroment variables in linked list
 * Return: Linked list with envorioment varibales, NULL if fails
 */
token_s *_start_env(void)
{
	int i;
	token_s *env = NULL;

	for (i = 0; environ[i]; i++)
		if (addnode(&env, environ[i], 0) == NULL)
			return (NULL);
	return (env);
}

/**
 * _getenv - Gets specific enviroment variable
 * @name: Variable to search for
 * @vars: Variables
 * Return: Enviroment variable, NULL if fails
 */
char *_getenv(char *name, var_s *vars)
{
	int i, j, size;
	char *var, *res;
	token_s *tmp = vars->env;

	size = _strlen(name);
	for (i = 0; tmp != NULL; i++)
	{
		var = tmp->str;
		for (j = 0; var[j] == name[j]; j++)
			;
		if (var[j] == '=')
		{
			if (size == j++)
			{
				for (; var[j]; j++)
					;
				res = malloc(sizeof(char) * j - size);
				if (!res)
					return (NULL);
				size++;
				for (j = 0; var[size]; size++, j++)
					res[j] = var[size];
				res[j] = '\0';
				return (res);
			}
		}
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * PrintEnviroment -  prints all the enviroment variables
 * @vars: Variables
 * Return: 0 Success, 1 Fails
 */
int PrintEnviroment(var_s *vars)
{
	token_s *tmp = vars->env;

	while (tmp)
	{
		if (!(*tmp).str)
		{
			write(STDOUT_FILENO, "nil", 4);
			write(STDOUT_FILENO, "\n", 2);
		}
		else
		{
			write(STDOUT_FILENO, tmp->str, _strlen(tmp->str));
			write(STDOUT_FILENO, "\n", 2);
		}
		tmp = (*tmp).next;
	}

	vars->status = 0;
	return (0);
}


/**
 * _setenv - Sets a enviroment variable
 * @vars: Variables
 * Return: Enviroment variable, NULL if fails
 */
int _setenv(var_s *vars)
{
	char *name = vars->tokens[1];
	char *value;
	char *new;

	if (name == NULL || name[0] == '\0')
	{
		vars->status = -1;
		vars->err_msm = "usage: setenv VARIABLE VALUE\n";
		return (0);
	}
	value = vars->tokens[2];
	if (value == NULL || value[0] == '\0')
	{
		vars->status = -1;
		vars->err_msm = "usage: setenv VARIABLE VALUE\n";
		return (0);
	}
	if (_getenv(name, vars) != NULL)
		_unsetenv(vars);
	new = malloc(_strlen(name) + _strlen(value) + 2);
	if (!new)
		return (0);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	if (addnode(&vars->env, new, 1) == NULL)
		return (0);

	vars->status = 0;
	return (0);
}
/**
 * _unsetenv - Unsets a enviroment variable
 * @vars: Variables
 * Return: 0 Success, -1 Failed
 */
int _unsetenv(var_s *vars)
{
	char *name = vars->tokens[1];
	unsigned int i, j;
	char *var;
	token_s *tmp = vars->env;

	if (name == NULL || name[0] == '\0')
	{
		vars->status = -1;
		vars->err_msm = "usage: unsetenv VARIABLE\n";
		return (0);
	}

	for (i = 0; tmp != NULL; i++)
	{
		var = tmp->str;
		for (j = 0; var[j] == name[j]; j++)
			;
		if (var[j] == '=')
		{
			if (delete_nodeint_at_index(&vars->env, i) == -1)
				return (0);
			break;
		}
		tmp = tmp->next;
	}

	vars->status = 0;
	return (0);
}
