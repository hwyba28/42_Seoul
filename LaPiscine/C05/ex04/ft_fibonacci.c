int    ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index < 2)
        return (index);
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

/*
 1 0
 1 2
 3
 */
int main(void){
    printf("%d",ft_fibonacci(10));//n번째 항 반환
}
