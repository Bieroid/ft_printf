#include "ft_printf.h"

int	ft_number_reduction(t_list *flags, int number)
{
	int	flag;

	flag = 0;
	if (flags->indent == 1 && !flags->dot)
	{
		if (number < 0)
		{
			ft_putchar('-');
			flag = 1;
		}
		ft_putchar('0');
	}
	else
		ft_putchar(' ');
	return (flag);
}
