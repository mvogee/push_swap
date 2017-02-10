// 42 header

#include "../checker/checker.h"
//#include "push_swap/push_swap.h"

void	do_push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*newhead_one;
	t_stack	*newhead_two;

	newhead_one = (*stack2);
	newhead_two = (*stack2)->next;
	newhead_one->next = *stack1;
	*stack1 = newhead_one;
	*stack2 = newhead_two;
}