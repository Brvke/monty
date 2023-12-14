#include "monty.h"
/**
 * rotr - Function that rotate the top of the stack
 * @stack: stack structure
 * @line_number: number of instruction
 */

void rotr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
		return;
	if ((*stack)->next == NULL)
		return;

	temp = (*stack);
	for (; temp->next; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
 * rotl - Function that rotate the *TOP of the*TOP
 * @TOP: TOP structure
 * @line_count: number of instruction
 */

void rotl(stack_t **TOP, __attribute__ ((unused)) unsigned int line_count)
{
	stack_t *temp = NULL;

	if (*TOP == NULL)
		return;
	if ((*TOP)->next == NULL)
		return;

	temp = (*TOP);
	for (; temp->next; temp = temp->next)
		;

	temp->next = *TOP;
	(*TOP)->prev = temp;
	temp = (*TOP)->next;
	(*TOP)->next = NULL;
	temp->prev = NULL;
	*TOP = temp;
}
