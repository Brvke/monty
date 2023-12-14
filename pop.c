#include  "monty.h"
/**
 * pop - function that removes to top of stack
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void pop(stack_t **TOP, unsigned int line_count)
{
	stack_t *temp;

	if (*TOP == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}

	temp = *TOP;
	*TOP = temp->next;
	if (*TOP)
		(*TOP)->prev = NULL;
	free(temp);
}
