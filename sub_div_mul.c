#include "monty.h"
/**
 * sub - function that sub to top of stack
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void sub(stack_t **TOP, unsigned int line_count)
{
	stack_t *first, *second;

	if (*TOP == NULL || (*TOP)->next == NULL)
	{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}

	first = *TOP;
	second = (*TOP)->next;
	second->n = second->n - first->n;
	pop(TOP, line_count);
}

/**
 * _div - function that divss to top of stack
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void _div(stack_t **TOP, unsigned int line_count)
{
	stack_t *first, *second;

	if (*TOP == NULL || (*TOP)->next == NULL)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_count);
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
	second->n = second->n / first->n;
	pop(TOP, line_count);
}

/**
 * mul - function that muls to top of stack
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */

void mul(stack_t **TOP, unsigned int line_count)
{
	stack_t *first, *second;

	if (*TOP == NULL || (*TOP)->next == NULL)
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
	}

	first = *TOP;
	second = (*TOP)->next;
	second->n = first->n * second->n;
	pop(TOP, line_count);
}
