# push_swap
Stack sorting algorithm project<br><br>
<b>Make compiles two programs. checker and push_swap.</b><br>
- The checker program reads arguments from the standard output and takes the stack as argument.<br>
It executes the given commands on the stack displaying OK if the stack is properly sorted and KO if not.<br><br>
- The push_swap program takes the stack as an argument and will print the propper commands to efficiently sort the numbers<br>

Example run: $>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG

 <b>how it works</b><br>
• The game is composed of 2 stacks named A and B.<br>
• To start with:<br>
A contains a random number of either positive or negative numbers without
any duplicates.<br>
B is empty<br>
• The goal is to sort the stack in ascending order into stack A.<br>
• To do this you the following operations are available:<br>
<b>sa</b>: swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).<br>
<b>sb</b>: swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).<br>
<b>ss</b>: sa and sb at the same time.<br>
<b>pa</b>: push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.<br>
<b>pb</b>: push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.<br>
<b>ra</b>: rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.<br>
<b>rb</b>: rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.<br>
<b>rr</b>: ra and rb at the same time.<br>
<b>rra</b>: reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.<br>
<b>rrb</b>: reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.<br>
<b>rrr</b>: rra and rrb at the same time.<br>
