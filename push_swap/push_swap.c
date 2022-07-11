#include "push_swap.h"

//1. 스택 초기화
void	init_stack(t_ab *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->a_size = 0;
	stack->b_size = 0;
}

int	double_check(t_node **head, long int n, int size)//& stack.a를 일부러 주소반환값을 이중포인터로 받음/값 접근 위해
{
	int			i;
	t_node	*tmp;

	i = 0;
	tmp = *head;//중복체크 tmp(a스택을 가르킴) -> (value 각 인자)
	while (i < size)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->next;
		i++;
	}
	if (n > 2147483647 || n < -2147483648)//int 범위
		return (1);
	return (0);
}

int	already_sorted(t_node **head)
{
	t_node	*tmp;
	t_node *last;

	tmp = *head;
	last = (*head)->prev;
	if (!(tmp))
		return (-1);
	while (tmp != last) // 마지막까지 정렬이 원래 되어있는 건지 확인
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	long int	n;
	t_ab		stack;
	t_node	*tmp;

	i = 1;
	init_stack(&stack);//두개 스택 생성 후 초기화
	if (argc > 1)
	{
		while (argv[i]) // 2 30 4 20 5 1..
		{
			n = ft_atoi(argv[i]);//숫자로 변환-각 수
			tmp = createNode(n);//스택 한개 제작 -- 자기 자신이 prev,next
			if (!tmp || double_check(&stack.a, n, stack.a_size)) // 현재까지 들어온 중복체크
			{
				write(2, "Error\n", 6);
				return (0);
			}//error 안났을때.
			add_element_top(&stack.a, tmp);//a노드에 tmp추가
			stack.a_size = i, i++;//현재까지 a스택에 추가된 수
		}
		if (already_sorted(&stack.a))//정렬되어있는지 여부, 됐으면 정렬 불필요.. 안되면 아래 코드 실행
			sort(&stack, argc);
	}
    //인자 안 들어왔을때 즉 1개 이하
	exit(EXIT_SUCCESS);
}
