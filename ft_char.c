#include "ft_printf.h"

int	ft_char(int c, t_list *flags)
{
	int	width;
	int	length;

	width = flags->width - 1;
	length = 1;
	if (flags->indent == 0 || flags->indent == 1)
	{
		while (width-- > 0 && length++)
		{
			if (flags->indent == 0)
				ft_putchar(' ');
			else
				ft_putchar('0');
		}
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		while (width-- > 0 && length++)
			ft_putchar(' ');
	}
	return (length);
}
