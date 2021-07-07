#include "ft_printf.h"

static int ft_reduction(char **s, t_list *flags, int *length)
{
    int width;
    int count_zero;
    int rub;

    count_zero = 0;
    if (flags->accur >= *length)
        count_zero = flags->accur - *length;
    if (flags->width >= flags->accur)
    {
        width = flags->width - count_zero - *length;
        rub = flags->width;
    }
    else
    {
        width = flags->accur - *length;
        rub = flags->accur;
    }
    if (rub < *length || (flags->accur < 0 && flags->prime_acc == 0))
    {
        ft_putstr("0x");
        ft_putstr(*s);
        return (0);
    }
    if (flags->indent == 0 || (flags->indent == 1 && (flags->dot)))
    {
        while ((flags->width >= flags->accur) && width-- > 0)
        {
            ft_putchar(' ');
            *length = *length + 1;
        }
        while(count_zero-- > 0)
        {
            ft_putchar('0');
            *length = *length + 1;
        }
        ft_putstr("0x");
        ft_putstr(*s);
        return(0);
    }
    if (flags->indent == 1)
    {
        while (width-- > 0)
        {
            ft_putchar('0');
            *length = *length + 1;
        }
        ft_putstr("0x");
        ft_putstr(*s);
        return(0);
    }
    if (flags->indent == 2)
    {
        while(count_zero-- > 0)
        {
            ft_putchar('0');
            *length = *length + 1;
        }
        ft_putstr("0x");
        ft_putstr(*s);
        while ((flags->width >= flags->accur) && width-- > 0)
        {
            ft_putchar(' ');
            *length = *length + 1;
        }
        return (0);
    }
    return (0);
}

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

int ft_pointer(size_t n, t_list *flags)
{
    char *s;
    int count_space;
    int length;

    if (n == 0 && flags->real_acc == 1)
    {
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
    s = ft_convert_p(n, "0123456789abcdef");
    length = 2 + ft_strlen(s);
    ft_reduction(&s, flags, &length);
    free(s);
    return (length);
}