#include "monty.h"
/**
 * push - function that pushes node to top of stack
 *
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 * @n: value to be stored in node
 */
void push(stack_t **TOP, unsigned int line_count, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed %d\n", line_count);
		freestack(*TOP);
		exit(EXIT_FAILURE);
}
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if ((*TOP) != NULL)
	{
		new->next = (*TOP);
		(*TOP)->prev = new;
	}
	*TOP = new;

}

/**
 * pall - function that prints all of stack value
 *
 * @TOP: pointer to top of stack
 * @line_count: count of lines printed
 */
void pall(stack_t **TOP, __attribute__ ((unused)) unsigned int line_count)
{
	stack_t *temp;

	temp = *TOP;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
