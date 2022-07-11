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
		len += ft_print_unsigned_int(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		len += ft_print_ptr(va_arg(ap, unsigned long long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		whole_len;
	va_list	ap;

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
			whole_len += ft_printchar(str[i]);
		i++;
	}
	va_end(ap);
	return (whole_len);
}
