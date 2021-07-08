#include "ft_printf.h"

static int	ft_reduction(int number, t_list *flags, int *length)
{
	int	width;
	int	flag;

	flag = 0;
	width = flags->width - ft_intlen(number);
	if (!flags->null && !flags->minus && \
		((flags->width - flags->accur > 0) || (width > 0)))
	{
		if (ft_intlen(number) < flags->accur)
			width = flags->width - flags->accur;
		if (number < 0)
			width--;
		while (width-- > 0)
		{
			flag = ft_number_reduction(flags, number);
			*length = *length + 1;
		}
	}
	return (flag);
}

static void	ft_minus(int *number, int *width, int *length, int flag)
{
	if (*number < 0)
	{
		if (flag == 0)
			ft_putchar('-');
		*length = *length + 1;
		*number = (-1) * (*number);
		*width = *width - 1;
	}
}

static int	ft_output(int number, t_list *flags, int *length, int flag)
{
	int	accur;
	int	width;

	width = flags->width - ft_intlen(number);
	accur = flags->accur - ft_intlen(number);
	if ((accur > 0) || ((flags->null || \
		(flags->indent == 1 && !flags->dot)) && width > 0))
	{
		ft_minus(&number, &width, length, flag);
		if (accur < width && flags->null)
			accur = width;
		while (accur > 0)
		{
			ft_putchar('0');
			*length = *length + 1;
			accur--;
		}
	}
	else if (number < 0)
		*length = *length + 1;
	return (number);
}

static void	ft_close(int number, t_list *flags, int *length, int n)
{
	int	width;
	int	socr;

	width = flags->width - flags->accur;
	socr = ft_intlen(number);
	if (flags->minus && ((flags->width > socr) || \
		(flags->width > flags->accur)))
	{
		if (socr > flags->accur)
			width = flags->width - socr;
		if (n < 0)
			width--;
		while (width-- > 0)
		{
			ft_putchar(' ');
			*length = *length + 1;
		}
	}
}

int	ft_number(int n, t_list *flags)
{
	int	length;
	int	number;
	int	flag;

	length = 0;
	number = n;
	flag = ft_reduction(number, flags, &length);
	number = ft_output(number, flags, &length, flag);
	if ((number == 0) && (flags->accur == 0) && (flags->dot))
	{
		if (flags->width)
		{
			ft_putchar(' ');
			length++;
		}
	}
	else
	{
		ft_putnbr(number);
		length = length + ft_intlen(number);
	}
	ft_close(number, flags, &length, n);
	return (length);
}
