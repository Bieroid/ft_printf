#include "ft_printf.h"

void	ft_flags_zero(t_list **flags)
{
	(*flags)->indent = 0;
	(*flags)->accur = 0;
	(*flags)->width = 0;
	(*flags)->dot = 0;
	(*flags)->minus = 0;
	(*flags)->null = 0;
	(*flags)->prime_acc = 0;
	(*flags)->real_acc = 0;
}

int	ft_indent(char const *format, int *i, t_list **flags)
{
	int	a;

	a = 0;
	if (format[*i] == '0')
	{
		a = 1;
		(*flags)->null = 1;
		*i = *i + 1;
	}
	if (format[*i] == '-')
	{
		(*flags)->minus++;
		(*flags)->null = 0;
		*i = *i + 1;
		a = 2;
	}
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '-')
			(*flags)->null = 0;
		*i = *i + 1;
	}
	return (a);
}

int	ft_width(va_list *ap, char const *format, int *i)
{
	int	a;

	if (format[*i] == '*')
	{
		a = va_arg(*ap, int);
		*i = *i + 1;
	}
	else
		a = ft_atoi(format + *i);
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	return (a);
}

int	ft_accur_reduction(int a, char const *format, int *i, t_list **flags)
{
	while (ft_isdigit(format[*i]))
		*i = *i + 1;
	(*flags)->prime_acc = a;
	if (a == 0 || a == -1)
		(*flags)->real_acc = 1;
	return (a);
}

int	ft_accur(va_list *ap, char const *format, int *i, t_list **flags)
{
	int	a;
	int	flag;

	flag = 1;
	if (format[*i] == '.')
		*i = *i + 1;
	else
		return (0);
	(*flags)->dot = 1;
	(*flags)->null = 0;
	while (format[*i] == '-')
	{
		*i = *i + 1;
		flag = -1;
	}
	if (format[*i] == '*')
	{
		a = va_arg(*ap, int);
		*i = *i + 1;
		if (a < 0)
			(*flags)->dot = 0;
	}
	else
		a = ft_atoi(format + *i) * flag;
	return (ft_accur_reduction(a, format, i, flags));
}
