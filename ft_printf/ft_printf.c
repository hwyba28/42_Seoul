#include "ft_printf.h"

int	ft_format(va_list ap, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_printstr(va_arg(ap, char *));
    else if (format == '%')
        len += ft_printpercent();
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_print_unsignedint(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_printhex(va_arg(ap, unsigned int), format);
    else if (format == 'p')
        len += ft_printptr(va_arg(ap, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
    int     whole_len;
    va_list	ap; // 가변인자 목록 포인터

	i = 0;
	whole_len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			whole_len += ft_format(ap, str[i + 1]);
			i++;
		}
		else
			whole_len += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (whole_len);
}
//... = 가변인자
//va_list: 가변인자 목록 저장 (가변인자 포인터)
//va_start: 포인터 설정
//va_arg: 특정자료형만큼 값 가져옴 + 포인터 이동 printf("나의 이름 %s 나이는 99살", name);
//va_end: 가변인자 처리 종료 후 NULL 초기화

//성능 문제 int보다 작은 자료형은 int로 받음 - va_arg
