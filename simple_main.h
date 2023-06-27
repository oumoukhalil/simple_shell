#ifndef _FATIMAH
#define _FATIMAH

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main_function(int ac, char **av, char **env);
void prompt_func(void);
void handle_signs(int signs);
void _EOF_(char *buffer);
void sh_exit(char **progname);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);

void create_child(char **progname, char *name, char **env, int fact);
int change_dir(const char *path);

void execute(char **progname, char *name, char **env, int fact);
void print_env(char **env);
char **_getPath(char **env);
void msgerror(char *name, int factcode, char **progname);

char **string_progname(char *buffer, const char *s);

void free_rp(char **progname);
void free_exit(char **progname);

#endif
