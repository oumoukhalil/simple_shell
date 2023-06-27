#include "simple_main.h"

/**
 * create_child - A function that creates a sub process.
 * @progname: The pointer to tokenized progname
 * @name: The pointer to the name of shell.
 * @env: The pointer to the enviromental variables.
 * @fact: Number of executed fact.
 */
void create_child(char **progname, char *name, char **env, int fact)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(progname);
	}
	else if (pid == 0)
	{
		execute(progname, name, env, fact);
		free_rp(progname);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(progname);
		}
		free_rp(progname);
	}
}


/**
  * change_dir - Afunction that changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
