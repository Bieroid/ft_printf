#include "ft_printf.h"

static void	ft_reduction(unsigned int number, t_list *flags, int *length)
{
	int	width;

	width = flags->width - ft_intlen(number);
	if (!flags->null && !flags->minus && \
		((flags->width - flags->accur > 0) || (width > 0)))
	{
		if (ft_intlen(number) < flags->accur)
			width = flags->width - flags->accur;
		while (width-- > 0)
		{
			if (flags->indent == 1 && (!flags->dot))
				ft_putchar('0');
			else
				ft_putchar(' ');
			*length = *length + 1;
		}
	}
}

static int	ft_output(unsigned int number, t_list *flags, int *length)
{
	int	accur;
	int	width;

	width = flags->width - ft_intlen(number);
	accur = flags->accur - ft_intlen(number);
	if ((accur > 0) || (flags->null && width > 0))
	{
		if (accur < width && flags->null)
			accur = width;
		while (accur > 0)
		{
			ft_putchar('0');
			*length = *length + 1;
			accur--;
		}
	}
	return (number);
}

static void	ft_close(unsigned int number, t_list *flags, int *length)
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
		while (width-- > 0)
		{
			ft_putchar(' ');
			*length = *length + 1;
		}
	}
}

int	ft_uns_numb(unsigned int n, t_list *flags)
{
	int				length;
	unsigned int	number;

	length = 0;
	number = n;
	ft_reduction(number, flags, &length);
	number = ft_output(number, flags, &length);
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
	ft_close(number, flags, &length);
	return (length);
}
