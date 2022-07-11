#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int    ft_format(va_list ap, const char format);
int    ft_printf(const char *str, ...);
int    ft_printchar(int c);
void   ft_putstr(char *str);
int    ft_printstr(char *str);
int    ft_printpercent(void);
int    ft_printnbr(int n);
static int    ft_strlen(const char *s)
static char    *ft_strrev(char *str)
char    *ft_itoa(int nbr)
int    ft_num_len(unsigned    int num)
char    *ft_unsigned_itoa(unsigned int n)
int    ft_print_unsigned_int(unsigned int n)
int    ft_hex_len(unsigned    int n)
void    ft_put_hex(unsigned int n, const char format)
int    ft_print_hex(unsigned int n, const char format)
void    ft_putchar_fd(char c, int fd)
int    ft_ptr_len(uintptr_t n)
void    ft_put_ptr(uintptr_t n)
int    ft_print_ptr(unsigned long long ptr)

//
//int		ft_printf(const char *format, ...);
//int		ft_format(va_list args, const char format);
//int		ft_printchar(char c);
//int		ft_printstr(char *str);
//int		ft_print_ptr(unsigned long long ptr);
//int		ft_printnbr(int n);
//int		ft_print_unsigned(unsigned int n);
//int		ft_print_hex(unsigned int num, const char format);
//int		ft_print_percent(void);
//
//void	ft_putstr(char *str);
//void	ft_put_ptr(uintptr_t num);
//int		ft_ptr_len(uintptr_t num);
//char	*ft_uitoa(unsigned int n);
//int		ft_num_len(unsigned	int num);
//void	ft_put_hex(unsigned int num, const char format);
//int		ft_hex_len(unsigned	int num);
//
//void    ft_putchar_fd(char c, int fd);
//char    *ft_itoa(int nbr);

#endif
