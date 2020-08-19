#include "0_principal_header.h"

/**
 * _strcat2 - concatenates two strings
 * @dest: first string
 * @check: Flag to free dest.
 * @src: second string
 * Return: Concatenated string, NULL on Fail
 */
char *_strcat2(char *dest, int check, char *src)
{
	int len_1, len_2, i;
	char *new;

	len_1 = len_2 = 0;
	if (dest)
		len_1 = _strlen(dest);
	if (src)
		len_2 = _strlen(src);
	new = malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!new)
		return (NULL);
	for (i = 0; i < len_1 ; i++)
		new[i] = dest[i];
	if (check == 1)
		free(dest);
	for (; i < (len_1 + len_2) ; i++)
		new[i] = src[i - len_1];
	new[i] = '\0';

	return (new);
}
/**
 * _rev_str - Place string in reverse
 * @str: String to reverse
 * Return: Reversed string
 */
char *_rev_str(char *str)
{
	int start, end;
	char tmp;

	if (str && *str)
	{
		start = 0;
		end = _strlen(str) - 1;

		for (; start < end; start++, end--)
		{
			tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
		}
	}

	return (str);
}
/**
 * _itoa - Converts int to string
 * @num: Number to convert
 * Return: Pointer to converted number
 */
char *_itoa(int num)
{
	int i, tmp;
	char *res;

	if (num == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\n';
		return (res);
	}

	tmp = num;
	for (i = 0; tmp; i++)
		tmp /= 10;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	for (i = 0; num; i++)
	{
		res[i] = '0' + num % 10;
		num /= 10;
	}
	res[i] = '\0';
	_rev_str(res);

	return (res);
}

/**
 * _puts - Prints a string
 *
 * @string: String to print
 *
 * Return: Nothing
 */
int _puts(char *string)
{
	return (write(1, string, _strlen(string)));
}
