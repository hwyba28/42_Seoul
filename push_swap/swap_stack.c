#include "push_swap.h"

void	swap(t_node **head)
{
	int			tmp;

	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	swap_check(t_ab *stack, char c)//c 스택종류 구분인자
{
	if (c == 'a' && stack->a && stack->a->next)//비정렬 2개-a스택
	{
		swap(&stack->a);
		write(1, "sa\n", 3);
	}
	if (c == 'b' && stack->b && stack->b->next)
	{
		swap(&stack->b);
		write(1, "sb\n", 3);
	}
	if (c == 's' && stack->a && stack->a->next && stack->b && stack->b->next)
	{
		swap(&stack->a);
		swap(&stack->b);
		write(1, "ss\n", 3);
	}
}

//sa : a의 첫 번째 값과 두 번째 값 교체(값이 하나거나 없으면 동작하지 않음)
//sb : b의 첫 번째 값과 두 번째 값 교체(값이 하나거나 없으면 동작하지 않음)
//ss : sa & sb
