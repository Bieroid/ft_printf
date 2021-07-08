#include "ft_printf.h"

static	int	ft_comparison(int n1, int n2)
{
	if (!n2)
		return (n1);
	if (n1 > n2)
		return (n2);
	else
		return (n1);
}

static void	ft_reduction(char **s, t_list *flags, int *length)
{
	int	width;
	int	accur;

	accur = 0;
	if (flags->dot && ((flags->accur - ft_strlen(*s) < 0) || (!flags->accur)))
	{
		accur = flags->accur;
		(*s)[accur] = '\0';
	}
	if (!flags->minus && (flags->width > \
		ft_comparison(ft_strlen(*s), accur)))
	{
		width = flags->width - ft_comparison(ft_strlen(*s), accur);
		while (width-- > 0)
		{
			if (flags->null == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*length = *length + 1;
		}
	}
}

int	ft_string(char *str, t_list *flags)
{
	int		length;
	int		width;
	char	*s;

	length = 0;
	if (str == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(str);
	ft_reduction(&s, flags, &length);
	ft_putstr(s);
	length = length + ft_strlen(s);
	width = flags->width - ft_strlen(s);
	if (flags->minus && (width > 0))
	{
		while (width-- > 0)
		{
			ft_putchar(' ');
			length = length + 1;
		}
	}
	free(s);
	return (length);
}
