#include "push_swap.h"
//배열 중간값
int	search_mid(int *arr, int argc)
{
	int	min;
	int	max;
	int	mid;

	min = arr[0];
	max = arr[argc - 2];
	mid = arr[(argc - 1) / 2];
	return (mid);
}

void	sort_arr(int *arr, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
//a 스택-> 배열
int	*make_arr(t_ab *stack, int argc)
{
	int			i;
	int			*arr;
	t_node	*al;

	i = 0;
	al = stack->a;
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	while (i < argc - 1)
	{
		arr[i] = al->value;
		al = al->next;
		i++;
	}
	sort_arr(arr, argc);
	return (arr);
}
