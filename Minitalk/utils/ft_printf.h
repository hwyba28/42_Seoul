#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int    ft_format(va_list ap, const char format);
int    ft_printf(const char *str, ...);
int    ft_printchar(int c);
void   ft_putstr(char *str);
int    ft_printstr(char *str);
int    ft_printpercent(void);
int    ft_printnbr(int n);
char    *ft_strdup(const char *s1);
size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_appendc(char *start, char c);
size_t    ft_strlen(const char *s);
void    *ft_calloc(size_t count, size_t size);
int    ft_atoi(const char *str);
char    *ft_itoa(int n);
int    ft_num_len(unsigned    int num);
char    *ft_unsigned_itoa(unsigned int n);
int    ft_print_unsigned_int(unsigned int n);
int    ft_hex_len(unsigned    int n);
void    ft_put_hex(unsigned int n, const char format);
int    ft_print_hex(unsigned int n, const char format);
void    ft_putchar_fd(char c, int fd);
int    ft_ptr_len(uintptr_t n);
void    ft_put_ptr(uintptr_t n);
int    ft_print_ptr(unsigned long long ptr);

#endif
