// 42 header here

#include "push_swap.h"

//for this approach we make a sorted array of the numbers
//push all the numbers to b
//step throught he numbers looking for the first two numbers
//once one of the numbers is found push it back to a
// if they need to be swapped swap the possitions and continue to the  next two numbers in the array
// this is extremely innificient but for now we will role with it.

push_swap(t_all **all)
{
	int		*lookup;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	lookup = make_numberarray(all->stacka); //make this
	lookup = quicksort_descending(lookup); //make this
	push_all_a(&all->stacka); // make this
	while (all->sizeb > 0)
	{
		 if (all->stackb->value == lookup[i])
		 {
		 	all->sizeb -= 1;
		 	push(&all->stackb, &all->stacka);
		 }
		 if (all->stackb->value == lookup[i + 1])
		 {
		 	all->sizeb -= 1;
		 }
	}


}