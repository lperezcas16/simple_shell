#include "0_principal_header.h"

/**
 * _strlen - measure string length.
 * @s: value to size.
 * Return: string length.
 */
int _strlen(char *s)
{
	int count = 0;

	while (s[count])
		count++;
	return (count);
}
/**
 * _strdup - Duplicates a string
 * @str: string to duplicate
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	int i;
	char *new = NULL;

	if (str)
	{
		i = _strlen(str);
		new = malloc(sizeof(char) * i + 1);
		if (!new)
			return (NULL);
		for (i = 0; str[i]; i++)
			new[i] = str[i];
		new[i] = '\0';
	}

	return (new);
}
/**
 * _strcpy - Copy string to pointer.
 * @src: Copy string.
 * @dest: Paste string.
 * Return: 0.
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int n;

	for (n = 0; *(src + n) != '\0'; n++)
		;
	for (i = 0; i <= n; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * Return: Concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	for (dest_len = 0 ; dest[dest_len] != '\0' ; dest_len++)
		;
	for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares the two strings s1 and s2
 * @s1: string 1
 * @s2: string 2
 * Return: dest.
 */
int _strcmp(char *s1, char *s2)
{
	int c = 0;

	while (s1[c] != '\0')
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
		c++;
	}
	return (0);
}
