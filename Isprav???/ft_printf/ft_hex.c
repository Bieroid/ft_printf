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

int ft_hex(unsigned int n, t_list *flags, int rub)
{
    char *s;
    int count_space;
    int length;

    if (n == 0 && flags->accur == -1)
    {
        length = 0;
        count_space = flags->width;
        while (count_space-- > 0)
        {
            ft_putchar(' ');
            length++;
        }
		if (flags->prime_acc == -1)
        {
            ft_putchar('0');
            length++;
        }
        return (length);
    }
    if (rub == 0)
		s = ft_convert(n, "0123456789abcdef");
	else
		s = ft_convert(n, "0123456789ABCDEF");
    length = ft_strlen(s);
    ft_reduct(&s, flags, &length);
    free(s);
    return (length);
}