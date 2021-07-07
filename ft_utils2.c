#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	int		a;

	a = 0;
	while (str[a] != '\0')
		a++;
	s = malloc(sizeof(char) * a + 1);
	if (s == 0)
		return (0);
	while (a != -1)
	{
		s[a] = str[a];
		a--;
	}
	return (s);
}

int	ft_intlen(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}