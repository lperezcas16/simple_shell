#ifndef VARS_H
#define VARS_H
#include "0_principal_header.h"

/**
 * struct variables - Global varibales
 * @sh_name: Shell name
 * @buffer: Getline input
 * @tokens: in_line splited in double pointer
 * @loop_cnt: Shell interations counter
 * @env: Enviroment varibales
 * @address: Path where executable allocates
 * @paths: Linked list with paths
 * @status: Execve output status
 * @err_msm: Error message
 *
 * Description: Structure containing common variables
 *
 */
typedef struct variables
{
	char *sh_name;
	char *buffer;
	char **tokens;
	int *loop_cnt;
	token_s *env;
	char *address;
	path_list *paths;
	int status;
	char *err_msm;
} var_s;
/* ----------------------------*/
/* ----------Prototypes------- */
/* ----------------------------*/
void InicializadorShell(var_s *vars, char *av, int *cnt);

#endif
