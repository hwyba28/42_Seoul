#include "push_swap.h"

t_node    *createNode(int data)//ex 7
{
    t_node    *one;

    one = (t_node *)malloc(sizeof(t_node));
    if (!one)
        return (0);//구조체 동적할당 후
    one->value = data;
    one->next = one;
    one->prev = one;
    return (one);
}

//맨앞에 추가
//연결리스트로 스택만들기
void    add_element_top(t_node **a, t_node *new) //전체 리스트의 a값에 새로운 값 추가 과정 *a = a_stack 자체 의미(주소값저장되어있음)
{
    t_node    *al;

    al = *a;
    if (!al)//노드 하나도 없으면 들어오는 노드가 헤드
        *a = new;
    else // al 있는 경우 현재
    {
        new->next = al;//새로 - 현재-현재
        new->prev = al->prev;//null값
        al->prev->next = new;
        al->prev = new;
    }//결론은 앞쪽에다가 새로운 노드 추가
} //-> stack 구조
