#ifndef AUX_H
#define AUX_H

#include "0_principal_header.h"

/* ----------------------------*/
/* ---------Prototypes---------*/
/* ----------------------------*/
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat2(char *dest, int check, char *src);
char *_rev_str(char *str);
char *_itoa(int num);
int _puts(char *string);

#endif
