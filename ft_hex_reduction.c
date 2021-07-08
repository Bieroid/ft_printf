#include "ft_printf.h"

static int	ft_red2(t_list *flags, int *length, int *width, int *rub)
{
	int	count_zero;

	count_zero = 0;
	if (flags->accur >= *length)
		count_zero = flags->accur - *length;
	if (flags->width >= flags->accur)
	{
		*width = flags->width - count_zero - *length;
		*rub = flags->width;
	}
	else
	{
		*width = flags->accur - *length;
		*rub = flags->accur;
	}
	return (count_zero);
}

static int	ft_red3(char **s, t_list *flags, int *width, int *count_zero)
{
	int	length;

	length = 0;
	while ((flags->width >= flags->accur) && *width > 0)
	{
		ft_putchar(' ');
		length = length + 1;
		*width = *width - 1;
	}
	while (*count_zero > 0)
	{
		ft_putchar('0');
		length = length + 1;
		*count_zero = *count_zero - 1;
	}
	ft_putstr(*s);
	return (length);
}

static int	ft_red4(char **s, t_list *flags, int *width, int *count_zero)
{
	int	length;

	length = 0;
	while (*count_zero > 0)
	{
		ft_putchar('0');
		length = length + 1;
		*count_zero = *count_zero - 1;
	}
	ft_putstr(*s);
	while ((flags->width >= flags->accur) && *width > 0)
	{
		ft_putchar(' ');
		length = length + 1;
		*width = *width - 1;
	}
	return (length);
}

static void	ft_red5(int *width, int *length, char **s)
{
	while (*width > 0)
	{
		ft_putchar('0');
		*length = *length + 1;
		*width = *width - 1;
	}
	ft_putstr(*s);
}

int	ft_hex_norm(char **s, t_list *flags, int *length)
{
	int	width;
	int	count_zero;
	int	rub;

	rub = 0;
	width = 0;
	count_zero = ft_red2(flags, length, &width, &rub);
	if (rub < *length || (flags->accur < 0 && flags->prime_acc == 0))
	{
		ft_putstr(*s);
		return (0);
	}
	if (flags->indent == 0 || (flags->indent == 1 && (flags->dot)))
	{
		*length = *length + (ft_red3(s, flags, &width, &count_zero));
		return (0);
	}
	if (flags->indent == 1)
		ft_red5(&width, length, s);
	if (flags->indent == 2)
		*length = *length + (ft_red4(s, flags, &width, &count_zero));
	return (0);
}
