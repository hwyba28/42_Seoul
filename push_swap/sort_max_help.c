#include "push_swap.h"
//회전 score 횟수
int	abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

void	rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score)
{
	while (*rot_b_score > 0 && *rot_a_score > 0)
	{
		rotate_check(stack, 'r');
		--*rot_b_score;
		--*rot_a_score;
	}
	while (*rot_a_score > 0)
	{
		rotate_check(stack, 'a');
		--*rot_a_score;
	}
	while (*rot_b_score > 0)
	{
		rotate_check(stack, 'b');
		--*rot_b_score;
	}
}

void	rev_rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score)
{
	while (*rot_b_score < 0 && *rot_a_score < 0)
	{
		reverse_rotate_check(stack, 'r');
		++*rot_b_score;
		++*rot_a_score;
	}
	while (*rot_a_score < 0)
	{
		reverse_rotate_check(stack, 'a');
		++*rot_a_score;
	}
	while (*rot_b_score < 0)
	{
		reverse_rotate_check(stack, 'b');
		++*rot_b_score;
	}
}

void	rot_and_push_ba(t_ab *stack, t_node *min_score, int position)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = calc_rot_a(stack, min_score->value);
	if (position < stack->b_size - position)
		rot_b_score = position;
	else
		rot_b_score = position - stack->b_size;
	if (rot_b_score > 0 || rot_a_score > 0)
		rot_ba(stack, &rot_a_score, &rot_b_score);
	if (rot_b_score < 0 || rot_a_score < 0)
		rev_rot_ba(stack, &rot_a_score, &rot_b_score);
	push_check(stack, 'a');
}

void	forw_or_rev(t_ab *stack)
{
	t_node	*tmp;
	int			i;
	int			max_a;

	i = 0;
	tmp = stack->a;
	max_a = search_max(&stack->a, stack->a_size);
	while (i < stack->a_size && tmp->value < max_a)
	{
		tmp = tmp->next;
		i++;
	}
	while (already_sorted(&stack->a)) //정렬은 되어있고, 회전 맞추기
	{
		if (i < stack->a_size - i)
			rotate_check(stack, 'a');
		else
			reverse_rotate_check(stack, 'a');
	}
}
