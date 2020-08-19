#include "0_principal_header.h"

/**
 * InicializadorTokenizar - Split arguments line into words
 * @vars: Variables
 * Return: Double pointer with splited words
 */
void InicializadorTokenizar(var_s *vars)
{
	char *token, **array;
	token_s *head, *tmp;
	int i;

	head = NULL;
	token = strtok(vars->buffer, " \n");
	for (i = 0; token; i++)
	{
		addnode(&head, token, 0);
		token = strtok(NULL, " \n");
	}
	array = malloc(sizeof(char *) * (i + 1));
	if (!array)
		return;
	for (; i >= 0; i--)
		array[i] = NULL;
	tmp = head;
	for (i = 0; tmp; i++)
	{
		array[i] = (char *)tmp->str;
		tmp = tmp->next;
	}
	free_list(&head);
	vars->tokens = array;
}

/**
 * _pipes - Filter command
 * @vars: Variables
 * Return: 0 Success, Other if fails
 */
int _pipes(var_s *vars)
{	/* Stores info about files */
	struct stat st;
	int aux = -1, pat = 1;
	DIR *folder;

	if (!_strcmp(vars->tokens[0], "."))
		return (0);
	if (built_in(vars->tokens[0])(vars) == 0)
		return (aux);
	folder = opendir(vars->tokens[0]);
	if (folder)
	{
		closedir(folder), vars->status = 126;
		return (aux);
	}
	if (vars->tokens[0][0] == '/' || vars->tokens[0][0] == '.')
	{
		if (stat(vars->tokens[0], &st) == 0)
			if (!access(vars->tokens[0], X_OK)) /* check permisos */
			{
				vars->status = 0;
				vars->address = vars->tokens[0];
			}
			else
				vars->status = 126;
		else
			vars->status = 127;
	}
	else
		pat = _checks_path(vars);

	if (vars->status == 0)
		aux = _executes(vars);
	if (pat == 0)
		free(vars->address);
	if (aux == 0)
		vars->status = 0;
	return (aux);
}

/**
 * _executes - Executes command
 * @vars: Variables
 * Return: 0 Success, Other if fails
 */
int _executes(var_s *vars)
{
	pid_t pid;
	int status = -1;
	char **env;

	pid = fork();
	if (pid == -1)
	{
		vars->status = -1;
		vars->err_msm = "Error spawning child process\n";
	}
	env = _envtoarray(vars);
	if (pid != 0)
	{
		wait(&status);
		vars->status = WEXITSTATUS(status);
		free(env);
	}
	else
	{
		execve(vars->address, vars->tokens, env);
	}

	return (status);
}

/**
 * _checks_path - Checks if command is in path
 * @vars: Variables
 * Return: 0 Success, -1 Failed
 */
int _checks_path(var_s *vars)
{
	char *address = NULL;
	path_list *tmp;
	struct stat st;
	int res = 0;

	_start_path(vars);
	tmp = vars->paths;
	while (tmp != NULL)
	{
		address = _strcat2(tmp->pat, 0, "/");
		address = _strcat2(address, 1, vars->tokens[0]);
		if (stat(address, &st) == 0)
			break;
		free(address);

		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		res = -1;
		vars->status = 127;
		vars->address = vars->tokens[0];
	}
	else
	{
		if (!access(address, X_OK))
		{
			vars->status = 0;
			vars->address = address;
		}
		else
		{
			res = -1;
			vars->status = 126;
		}
	}

	free_path_list(&vars->paths);

	return (res);
}

/**
 * _start_path - Checks if command is in path
 * @vars: Variables
 * Return: Pointer to path on success, NULL if fails
 */
void _start_path(var_s *vars)
{
	char *token, *paths;
	path_list *head = NULL;

	paths = _getenv("PATH", vars);

	token = strtok(paths, ":");
	while (token)
	{
		add_path_node(&head, token);
		token = strtok(NULL, ":");
	}
	free(paths);

	vars->paths = head;
}
