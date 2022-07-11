#include "push_swap.h"
//a 로테이션 횟수
int	calc_rot_a(t_ab *stack, int value)
{
	int			rot;
	t_node	*tmp;
	int			i;

	i = 1;
	rot = 0;
	tmp = stack->a;//a스택
	while (value > tmp->value || tmp->prev->value > value)//맨 위나 아래로삽입가능할때 범위가..
	{
		tmp = tmp->next;
		rot++;
	}
	if (rot < stack->a_size - rot)
		return (rot);
	else
		return (rot - stack->a_size);
}

void	sum_score(t_ab *stack, t_node *tmp, int position)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = calc_rot_a(stack, tmp->value);//n
	if (position < stack->b_size - position)
		rot_b_score = position;
	else
		rot_b_score = position - stack->b_size;
	if ((rot_a_score > 0 && rot_b_score > 0)
		|| (rot_a_score < 0 && rot_b_score < 0))
	{
		if (abs(rot_a_score) > abs(rot_b_score))
			tmp->elem_score = abs(rot_a_score);
		else
			tmp->elem_score = abs(rot_b_score);
	}
	else
		tmp->elem_score = abs(rot_b_score) + abs(rot_a_score);
}

t_node	*search_min_score(t_ab *stack, int *position)
{
	int			i;
	t_node	*tmp;
	t_node	*min_score_elem;

	i = 1;
	*position = 0;
	tmp = stack->b->next;
	min_score_elem = stack->b;
	while (i < stack->b_size)
	{
		if (tmp->elem_score < min_score_elem->elem_score && tmp)
		{
			*position = i;
			min_score_elem = tmp;
		}
		if (tmp->elem_score < min_score_elem->elem_score
			&& tmp->value < min_score_elem->value && tmp)
		{
			*position = i;
			min_score_elem = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_score_elem);
}

void	next_step(t_ab *stack)
{
	t_node	*tmp;
	t_node	*min_score;
	int			i;
	int			position;

	i = 0;
	tmp = stack->b;
	while (i < stack->b_size)
	{
		sum_score(stack, tmp, i);
		tmp = tmp->next;
		i++;
	}
	min_score = search_min_score(stack, &position);
	rot_and_push_ba(stack, min_score, position);
}

void	sort_max(t_ab *stack, int argc)
{
	int	*sort_arr;
	int	mid;
	int	min;
	int	max;

	sort_arr = make_arr(stack, argc);//a스택 정렬
	mid = search_mid(sort_arr, argc);//a스택 중간값
	min = sort_arr[0];
	max = sort_arr[argc - 2];//배열은 중간 끝값만 알기 위한 방법
    //현실에서 Date기준으로 정렬이되었지만 데이터 자체가 정렬되기 위해서는 통째로 움직여야함 아래..
	push_to_b(stack, min, max, mid);
	while (stack->b != NULL)
		next_step(stack);
	forw_or_rev(stack);//똑바로 또는 반대로 정렬
	free(sort_arr);
}
