#include "push_swap.h"
//최소값 찾기
int	search_min(t_node **head, int size)
{
	int			i;
	int			n;
	t_node	*tmp;

	i = 0;
	tmp = *head;
	n = tmp->value;
	while (i < size)
	{
		if (n > tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}
//최대값 찾기
int	search_max(t_node	**head, int size)
{
	int			i;
	int			n;
	t_node	*tmp;

	i = 0;
	tmp = *head;
	if (!*head)
		return (0);
	n = tmp->value;
	while (i < size)
	{
		if (n < tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}
//
/*
 |
 |
 |
 */
void	sort3(t_ab	*stack)
{
	int			min;
	int			max;
	t_node	*tmp;

	tmp = stack->a;//a스택
	min = search_min(&stack->a, stack->a_size);
	max = search_max(&stack->a, stack->a_size);
	while (already_sorted(&stack->a))//정렬될때까지
	{
		if (tmp->value == max)//첫번째(top)가 최대값일때
			rotate_check(stack, 'a'), tmp = stack->a;//한바퀴 돌려서 1번 작동 - 맨 아래 최댓값 나머지 모름
		if (tmp->value < tmp->next->value && tmp->next->value == max)//max 두번째 위치
			reverse_rotate_check(stack, 'a'), tmp = stack->a;
		if (tmp->value > tmp->next->value && tmp->next->value == min)// 2번째가 맨위보다 크고 두번째가 최소값일때, 맨위, 그 아래 swap 2 1 3 상태 원래 max가 3번째 경우 / 1번 조건문 걸린 상태 또는 / 2번조건문으로 max아래로 보낸 상태
			swap_check(stack, 'a'), tmp = stack->a;
	}
}

void	sort5(t_ab *stack)
{
	int			min;
	int			max;

	min = search_min(&stack->a, stack->a_size);
	max = search_max(&stack->a, stack->a_size);
	while (stack->a_size != 3) // 중간값 3개만 a스택에 남겨놓기
	{
		if (stack->a->value == max || stack->a->value == min)
			rotate_check(stack, 'a');
		else
			push_check(stack, 'b');
	}
	sort3(stack);
    /*
     2    1
     3    5
     4
     */
	reverse_rotate_check(stack, 'a');
	if (stack->b->value < stack->b->next->value)
		swap_check(stack, 'b');//
	while (stack->b)
	{
		while ((stack->b->value > stack->a->value)
			 || stack->a->prev->value > stack->b->value)
			reverse_rotate_check(stack, 'a');
		push_check(stack, 'a');
	}
	while (already_sorted(&stack->a))
		reverse_rotate_check(stack, 'a');
}

void	sort(t_ab *stack, int argc)
{
	if (argc == 3)
		swap_check(stack, 'a');
	else if (argc == 4)//인자 3개
		sort3(stack);
	else if (argc <= 6)//인자 5개-효율방식
		sort5(stack);
	else if (argc > 6)//5개 이상
		sort_max(stack, argc);
}
