// 42 header

#include "../checker/checker.h"
//#include "push_swap/push_swap.h"

void	do_rev_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*old_end;

	old_head = *stack;
	new_head = (*stack)->next;
	old_end = (*stack)->next;
	while (old_end->next)
		old_end = old_end->next;
	old_end->next = old_head;
	old_head->next = NULL;
	*stack = new_head;
}