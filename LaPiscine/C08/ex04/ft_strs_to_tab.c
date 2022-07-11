#include <stdlib.h>

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strcpy(char *dest, char *src)
{
    int c;

    c = 0;
    while (src[c] != '\0')
    {
        dest[c] = src[c];
        c++;
    }
    dest[c] = '\0';
    return (dest);
}

char    *ft_strdup(char *src)
{
    char *dest;

    dest = malloc((ft_strlen(src) + 1) * sizeof(char));
    if (dest != '\0')
        return (ft_strcpy(dest, src));
    else
        return (dest);
}

//동적할당으로 복사 완료///

//각항의 구조변환
struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*arr;

    arr = malloc((ac + 1) * sizeof(struct s_stock_str));
    
	if (!arr)
		return (NULL); // 헤더에 정의
	i = 0;
	while (i < ac)
	{//구조체 각요소
		arr[i].size = ft_strlen(av[i]); // 각 행문자열을 각 구조체로
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i] = (struct s_stock_str){0, 0, 0};//마지막항은 000으로 선언
	return (arr);
}
