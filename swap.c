#include "monty.h"
/**
 * swap - function that swap top of stack with second top
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void swap(stack_t **TOP, unsigned int line_count)
{
	stack_t *oldtop, *newtop, *temp;

	if (*TOP == NULL || (*TOP)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}
	oldtop = *TOP;
	newtop = (*TOP)->next;
	temp = newtop->next;
	newtop->next = oldtop;
	if (!temp)
		oldtop->next = NULL;
	else
	{
		oldtop->next = temp;
		temp->prev = oldtop;
	}
	oldtop->prev = newtop;
	newtop->prev = NULL;
	*TOP = newtop;
}
