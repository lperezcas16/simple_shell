#include "0_principal_header.h"

/**
 * InicializadorShell - Initialize shell variables
 * @vars: Struct variables
 * @av: Program name
 * @cnt: Pointer to program iteration
 * Return: Struct with variables
 */
void InicializadorShell(var_s *vars, char *av, int *cnt)
{
	vars->sh_name = av;
	vars->buffer = NULL;
	vars->tokens = NULL;
	vars->loop_cnt = cnt;
	vars->env = _start_env();
	vars->address = NULL;
	vars->paths = NULL;
	vars->status = 0;
	vars->err_msm = NULL;
}
