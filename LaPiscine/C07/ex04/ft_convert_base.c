#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int base_verify(char *base)
{
    int i;
    int j;
    
    if (ft_strlen(base) < 2)
        return (0);
    i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == '+' || base[i] == '-' || (base[i] >= '\t'
            && base[i] <= '\r') || base[i] == ' ')
            return (0);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

char *ft_convert_base(char *nbr, char *base_from, char* base_to)
{
	if (!base_verify(base_from) || !base_verify(base_to))
        return NULL;
    
}
