#include "ft_printf.h"

static char	*ft_convert(unsigned int a, char *s)
{
	unsigned int	i;
	unsigned int	q;
	char			*save;

	i = a;
	q = 1;
	i = i / 16;
	while (i)
	{
		i = i / 16;
		q++;
	}
	save = malloc(sizeof(char) * (q + 1));
	if (!save)
		return (NULL);
	save[q] = '\0';
	save[--q] = s[a % 16];
	a = a / 16;
	while (a)
	{
		save[--q] = s[a % 16];
		a = a / 16;
	}
	return (save);
}

static int	ft_hex_reduction(t_list *flags)
{
	int	count_space;
	int	length;

	length = 0;
	count_space = flags->width;
	if (flags->prime_acc == -1)
		count_space--;
	while (count_space > 0 && flags->minus == 0)
	{
		ft_putchar(' ');
		length++;
		count_space--;
	}
	if (flags->prime_acc == -1)
	{
		ft_putchar('0');
		length++;
	}
	while (count_space-- > 0)
	{
		ft_putchar(' ');
		length++;
	}
	return (length);
}

int	ft_hex(unsigned int n, t_list *flags, int rub)
{
	char	*s;
	int		length;

	if (n == 0 && flags->real_acc == 1 && (flags->indent != 1 || flags->dot))
		return (ft_hex_reduction(flags));
	if (rub == 0)
		s = ft_convert(n, "0123456789abcdef");
	else
		s = ft_convert(n, "0123456789ABCDEF");
	length = ft_strlen(s);
	ft_hex_norm(&s, flags, &length);
	free(s);
	return (length);
}
