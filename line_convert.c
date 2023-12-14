#include "monty.h"
/**
 * line2cmd - converts a line fromfile to
 *	a format more easily managlbe for later
 *
 * @line: a line form file being read
 * @command: output array
 *
 * Return: if sucess command if not NULL
 *
*/
char *line2cmd(char *line, char *command)
{
	int i, j;

	i = j = 0;


	while (line[i] == ' ')
		i++;
	if (line[i] == '\0' || line[i] == '$')
		return (NULL);
	while (line[i] != ' ' && line[i] != '\0' && line[i] != '\n')
	{
		command[j] = line[i];
		i++;
		j++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0' || line[i] != '$')
	{
		command[j] = ' ';
		j++;
	}
	while (line[i] != ' ' && line[i] != '\0' && line[i] != '$')
	{
		command[j] = line[i];
		i++;
		j++;
	}
	return (command);
}
