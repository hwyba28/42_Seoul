#include "push_swap.h"

void	push_to_b(t_ab *stack, int min, int max, int mid)
{
	while (stack->a_size > 2)
	{
		if (stack->a->value > mid && stack->a->value != max)
		{
			push_check(stack, 'b');
			rotate_check(stack, 'b');//b로 돌면서 하나씩 확인
		}
		else if (stack->a->value <= mid && stack->a->value != min)
			push_check(stack, 'b');
		else//max or min
			rotate_check(stack, 'a');
	}
	if (stack->a->value == min)
		rotate_check(stack, 'a');
}
