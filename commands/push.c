// 42 header

#include "push_swap.h"

void	do_push(t_stack **pushto, t_stack **pushfrom)
{
	t_stack	*newhead_to;
	t_stack	*newhead_from;

	newhead_to = (*pushfrom);
	if (*pushto)
		(*pushto)->prev = newhead_to;
	newhead_from = (*pushfrom)->next;
	if (newhead_from)
		(*pushfrom)->next->prev = NULL;
	newhead_to->next = *pushto;
	*pushto = newhead_to;
	*pushfrom = newhead_from;
}
