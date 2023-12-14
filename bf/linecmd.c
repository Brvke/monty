#include "monty.h"
/**
         * take line as input
         * start while loop
         * put all files that are not empty lines
         */
char *line2cmd(char *line, char *command)
{
        int i;
        char *temp;
        i = 0;
        printf("line: '%s', strlenline: %d", line,(int) strlen(line));
        if (strlen(line) < 2  || line == NULL)
                return (NULL);
        while(line[i] == ' ')
                i++;
        if (line[i] != '\0' || line[i] != '\n' || line[i] != '$')
                temp = strtok(line, " ");
        else 
                return (NULL);
        printf("command: '%s'  ", temp);
        /*while(line[i] == ' ')
                i++;*/
        if (line[i] != '\0' || line[i] != '\n' || line[i] != '$')
                strcat(strtok(NULL, " "),temp);
        printf("command: '%s'  ", temp);
        /*while (line[i] != '\0')
        {
                while (line[i] != ' ')
                {
                        command[j] = line[i];
                        j++;
                        if (line[i++] != ' ')
                        {      
                                command[j] = ' ';
                                i++;
                        }
                }
                i++;
        }*/
        command = temp;
        return (command);
}
