#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct  s_list
{
    int indent;
    int width;
    int accur;
    int real_acc;
}               t_list;

int     ft_printf(const char *format, ...);
void    ft_flags_zero(t_list **flags);
int     ft_indent(char const *format, int *i);
int     ft_width(va_list *ap, char const *format, int *i);
int     ft_accur(va_list *ap, char const *format, int *i);
void    ft_checker(t_list **flags);
int     ft_atoi(const char	*str);
int     ft_isdigit(int ch);
int     ft_search(char ch);
int     ft_putchar(char c);
int     ft_char(int c, t_list *flags);
int     ft_string(char *str, t_list *flags);
int     ft_strlen(const char *s);
char    *ft_substr(char const *s, int start, int len);
void    *ft_calloc(int num, int size);
void	ft_putstr(char *s);

#endif