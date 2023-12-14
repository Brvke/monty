#include "monty.h"
/**
 * freestack - frees a doubly linked list
 *
 * @TOP: pointer to TOP of stack
*/
void freestack(stack_t *TOP)
{
	stack_t *temp;

	temp = TOP;
	while (TOP != NULL)
	{
		temp = TOP;
		TOP = TOP->next;
		free(temp);
	}
}
