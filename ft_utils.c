#include "ft_printf.h"

int ft_search(char ch)
{
    if (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd')
        return (1);
    if (ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X')
        return (1);
    if (ch == '%')
        return (1);
    return (0);
}

int ft_putchar(char c)
{
    write(1, &c, 1);
    if (c == 0)
        return (0);
    return (1);
}

void	ft_putstr(char *s)
{
	int	a;

	if (s == 0)
		return ;
	a = ft_strlen(s);
	write(1, s, a);
}
