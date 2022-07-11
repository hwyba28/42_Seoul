#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	current;

	index = 0;
	while (true)
	{
		current = str[index];
		if (current == '\0')
			break ;
		if (current > ' ' && current !=127) //스페이스바의 아스키코드 32이고, del 키 제외
            //이후 값이 문자이므로.
			ft_putchar(current);
		else
		{
            int *hex = "0123456789abcdef";
			ft_putchar('\\'); // 16진수 최대 7배수 - 재귀 필요x
            ft_putchar(hex[current / 16]);//문자에 해당하는(캐스팅)을 16으로 나누기
			ft_putchar(hex[current % 16]);//여기서는 각 자리수 출력위해
		}
		index++;
	}
}

//아스키코드 구조표
