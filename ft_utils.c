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

static char *ft_itoa_socr(int b, int min, unsigned int a)
{
	char	*s;

	s = malloc(sizeof(char) * (b + min) + 1);
	if (s == 0)
		return (0);
	s[b + min] = '\0';
	if (min == 0)
		b--;
	while (b >= 0)
	{
		s[b] = (a % 10) + 48;
		a = a / 10;
		b--;
	}
	if (min == 1)
		s[0] = '-';
	return (s);
}

char    *ft_itoa(long int n)
{
	unsigned int	a;
	int				b;
	int				min;

	b = 0;
	min = 0;
	if (n < 0)
	{
		a = -n;
		min = 1;
	}
	else
		a = n;
	while (a != 0)
	{
		a = a / 10;
		b++;
	}
	if (min == 1)
		a = -n;
	else
		a = n;
	if (n == 0)
		b++;
	return (ft_itoa_socr(b, min, a));
}