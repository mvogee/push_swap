// 42 header

#include "../checker/checker.h"
//#include "push_swap/push_swap.h"

void	do_swap(t_stack **stack)
{
	t_stack	*new_head;
	t_stack *old_head;

	new_head = (*stack)->next;
	old_head = *stack;
	old_head->next = new_head->next;
	new_head->next = *stack;
	*stack = new_head;
}