#include "monty.h"
/**
 * main - monty interpreter
 * @ac: number of arguments used in command call
 * @av: array of arguments in command call
 *
 * Return: appropriate error
 */

/*
 * TODO
 *in push if int is not an int or if no argument given to push
 *	print the error message L<line_number>: usage: push integer,
 *	followed by a new line, and exit with the status EXIT_FAILURE
 * exit correctly (free stuff)
 * malloc failed checks: Error: malloc failed, exit failure
 *
 */
int main(int ac, char **av)
{
if (ac != 2)
{
dprintf(STDERR_FILENO, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
if (access(av[1], F_OK) != 0)
{
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}
else
{
getLinez(av[1]);
return (EXIT_SUCCESS);
}
}
