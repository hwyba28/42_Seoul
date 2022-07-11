#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//노드 한개
typedef struct s_node
{
	int					value;
	int					elem_score;
	struct s_node	*next;//이전노드
	struct s_node	*prev;//이전노드
}	t_node;
//두개 스택에 대한 정보
typedef struct s_ab
{
	struct s_node	*a;
	struct s_node	*b;
	int					a_size;
	int					b_size;
}	t_ab;

t_node	*createNode(int data);
void		add_element_top(t_node **a, t_node *new);
void		push_check(t_ab *stack, char c);
void		swap_check(t_ab *stack, char c);
void		rotate_check(t_ab *stack, char c);
void		reverse_rotate_check(t_ab *stack, char c);

long int	ft_atoi(const char *str);
void		sort(t_ab *stack, int argc);
int			already_sorted(t_node **head);

int			search_max(t_node	**head, int size);
int			search_min(t_node **head, int size);

void		sort_max(t_ab *stack, int argc);

int			check_rev_sort(t_ab *stack, char c);
int			*make_arr(t_ab *stack, int argc);
int			search_mid(int *arr, int argc);
int			abs(int num);
void		rot_and_push_ba(t_ab *stack, t_node *min_score, int position);
void		forw_or_rev(t_ab *stack);
void		push_to_b(t_ab *stack, int min, int max, int mid);
int			calc_rot_a(t_ab *stack, int value);

#endif
