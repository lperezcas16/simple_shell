#include "0_principal_header.h"

/**
 * print_error - Prints error messages
 * @vars: Variables
 * Return: Error number
 */
void print_error(var_s *vars)
{
	if (vars->status == 2 || vars->status == 2)
		return;
	/* "comando no ejecutable" */
	if (vars->status == 126)
		notaccess(vars);
	/* no se encuentra en ninguna de las rutas. */
	else if (vars->status == 127)
		notfound(vars);
	/* Ilegal numb */
	else if (vars->status == 7)
		ilegalnumber(vars);
	else if (vars->status == -1)
	{
		vars->status = 1;
		write(STDERR_FILENO, vars->err_msm, _strlen(vars->err_msm));
		return;
	}
	else
		write(STDOUT_FILENO, &vars->status, 4);
	/* Print the error */
	write(STDERR_FILENO, vars->err_msm, _strlen(vars->err_msm));
	free(vars->err_msm);
}

/**
 * notfound - Compiles error message
 * @vars: Variables
 * Return: Pointer to message
 */
void notfound(var_s *vars)
{
	char *message, *temp;
	char *num;

	num = _itoa(*vars->loop_cnt);
	message = temp = NULL;
	message = _strcat2(vars->sh_name, 0, ": ");
	message = _strcat2(message, 1, num);
	message = _strcat2(message, 1, ": ");
	message = _strcat2(message, 1, vars->tokens[0]);
	message = _strcat2(message, 1, ": not found\n");
	free(num);

	vars->err_msm = message;
}

/**
 * notaccess - Concatenate error message
 * @vars: Variables
 * Return: Pointer to message
 */
void notaccess(var_s *vars)
{
	char *message, *temp;
	char *num;

	num = _itoa(*vars->loop_cnt);
	message = temp = NULL;
	message = _strcat2(vars->sh_name, 0, ": ");
	message = _strcat2(message, 1, num);
	message = _strcat2(message, 1, ": ");
	message = _strcat2(message, 1, vars->tokens[0]);
	message = _strcat2(message, 1, ": Permission denied\n");
	free(num);

	vars->err_msm = message;
}

/**
 * ilegalnumber - Concatenate error message
 * @vars: Variables
 * Return: Pointer to message
 */
void ilegalnumber(var_s *vars)
{
	char *message, *temp;
	char *num;

	num = _itoa(*vars->loop_cnt);
	message = temp = NULL;
	message = _strcat2(vars->sh_name, 0, ": ");
	message = _strcat2(message, 1, num);
	message = _strcat2(message, 1, ": ");
	message = _strcat2(message, 1, vars->tokens[0]);
	message = _strcat2(message, 1, ": Illegal number: ");
	message = _strcat2(message, 1, vars->tokens[1]);
	message = _strcat2(message, 1, "\n");
	free(num);

	vars->status = 2;
	vars->err_msm = message;
}
