#include "ft_printf.h"

static void ft_reduction(char **s, t_list *flags, int *length)
{
    int width;

    width = flags->width - ft_strlen(*s);
    if (flags->indent == 0 || flags->indent == 1)
    {
        while (width-- > 0)
        {
            if (flags->indent == 0)
                ft_putchar(' ');
            else
                ft_putchar('0');
            *length = *length + 1;
        }
        ft_putstr(*s);
    }
    else
    {
        ft_putstr(*s);
        while (width-- > 0)
        {
            ft_putchar(' ');
            *length = *length + 1;
        }
    }
}

int ft_string(char *str, t_list *flags)
{
    int length;
    char *s;

    length = 0;
    if (str == 0)
    {
        if (flags->accur > 0 || flags->real_acc == 1)
            s = ft_substr("(null)", 0, flags->accur);
        else
            s = ft_substr("(null)", 0, 6);
    }
    else
    {
        if (flags->accur != 0 && flags->accur < ft_strlen(str))
            s = ft_substr(str, 0, flags->accur);
        else
            s = ft_substr(str, 0, ft_strlen(str));
    }
    length = ft_strlen(s);
    ft_reduction(&s, flags, &length);
    free(s);
    return (length);
}