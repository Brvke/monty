#include "monty.h"
/**
 * mod - function that adds to top of stack
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void mod(stack_t **TOP, unsigned int line_count)
{
	stack_t *first, *second;

	if (*TOP == NULL || (*TOP)->next == NULL)
	{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}

	first = *TOP;
	second = (*TOP)->next;
	if (first->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}
	second->n = second->n % first->n;
	pop(TOP, line_count);
}
