// 42 header

#include "push_swap.h"

void	do_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*last_node;
	t_stack	*previous;
	int		count;

	old_head = *stack;
	previous = *stack;
	last_node = (*stack)->next;
	count = 0;
	while (last_node->next)
	{
		previous = previous->next;
		last_node = last_node->next;
		count++;
	}
	if (count > 0)
		last_node->next = old_head->next;
	else
		last_node->next = old_head;
	previous->next = old_head;
	old_head->next = NULL;
	*stack = last_node;
}