#include "0_principal_header.h"

/**
 * print_help - Funtion to print whit help
 */
void print_help(void)
{
	_puts("These shell commands are defined internally.\n\n");
	_puts("\tType 'help' to see this list. Type 'help name'\n");
	_puts("\tto find out more about the function 'name'.\n\n");
	_puts("\texit [STATUS]\n");
	_puts("\tenv\n");
	_puts("\tsetenv [VARIABLE]\n");
	_puts("\tunsetenv [VARIABLE]\n");
	_puts("\thelp [BUILT-IN]\n");
}

/**
 * help_exit - Funtion for help exit
 */
void help_exit(void)
{
	_puts("exit: exit [STATUS]\n");
	_puts("\tExits the shell.\n");
}

/**
 * help_help - Shows information about built-in command "help".
 *
 */
void help_help(void)
{
	_puts("help: help [BUILT-IN]\n");
	_puts("\tDisplays information about built-in commands.\n\n");
	_puts("\tUsed as help [BUILT-IN] to give detailed help\n");
	_puts("\tof the command specified. Otherwise will print\n");
	_puts("\tthe list of help commands avaliable.\n");
}
