#include <stdio.h>
int        ft_is_prime(int nb)
{
    int i;

    i = 2;
    if (nb < 2)
        return (0);
    while (nb > i)
    {
        if (nb % i == 0)
        {
            nb++;
            i = 2;
            continue;
        }
        i++;
    }
    return (nb);
}

int		ft_find_next_prime(int nb)
{
            return (ft_is_prime(nb));
}

int main (void){
    printf("%d",ft_is_prime(45));
}
