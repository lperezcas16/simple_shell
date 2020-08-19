#include "0_principal_header.h"

/**
 * handler - handler signal interruption
 * @sig_num: unided variable
 */
void handler(__attribute__((unused)) int sig_num)
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - Shell main function
 * @ac: Arguments to initialize shell (UNUSED)
 * @av: Program name
 * Return: 0 Success, Other Failed.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 1, aux = 0;
	var_s vars;
	size_t in_len;
	/* No interactive mode */
	signal(SIGINT, handler);
	signal(SIGTSTP, SIG_IGN);
	/* Initilice for new space */
	InicializadorShell(&vars, av[0], &i);
	/* Search failures at the end of the file */
	while (aux != EOF)
	{	/* True if the file is connect whit terminal */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 3);
		/* Read line */
		aux = getline(&vars.buffer, &in_len, stdin);
		if (aux == -1)
			break;
		if (aux != 1)
		{/* Tokenize the buffer */
			InicializadorTokenizar(&vars);

			if (vars.tokens[0])
			{
				_pipes(&vars);
				if (vars.status != 0)
					print_error(&vars);
			}
			free(vars.tokens);
		}
		i++;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 2);
	free_list(&vars.env);
	free(vars.buffer);
	i = vars.status;

	return (i);
}
