#include "ft_printf.h"

static char	*ft_convert_p(size_t a, char *s)
{
	size_t	i;
	size_t	q;
	char	*save;

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

static int	ft_pointer_reduction(t_list *flags)
{
	int	count_space;
	int	length;

	length = 0;
	count_space = flags->width - 2;
	if (flags->indent == 2)
		ft_putstr("0x");
	while (count_space-- > 0)
	{
		ft_putchar(' ');
		length++;
	}
	if (flags->indent != 2)
		ft_putstr("0x");
	if (flags->prime_acc == -1)
	{
		ft_putchar('0');
		length++;
	}
	return (length + 2);
}

int	ft_pointer(size_t n, t_list *flags)
{
	char	*s;
	int		length;

	if (n == 0 && flags->real_acc == 1)
		return (ft_pointer_reduction(flags));
	s = ft_convert_p(n, "0123456789abcdef");
	length = 2 + ft_strlen(s);
	ft_pointer_norm(&s, flags, &length);
	free(s);
	return (length);
}
