#include "ft_printf.h"

int ft_reduct(char **s, t_list *flags, int *length)
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
    if (rub < *length || (flags->accur < 0 && flags->real_acc == 0))
    {
        ft_putstr(*s);
        return (0);
    }
    if (flags->indent == 0 || (flags->indent == 1 && (flags->dot)))
    {
        while ((flags->width >= flags->accur) && (width-- > 0) && (flags->prime_acc >= 0))
        {
            ft_putchar(' ');
            *length = *length + 1;
        }
        if (flags->prime_acc >= 0)
        {
            while(count_zero-- > 0)
            {
                ft_putchar('0');
                *length = *length + 1;
            }
        }
        else
        {
            while(width-- >= 0)
            {
                ft_putchar('0');
                *length = *length + 1;
            }
        }
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

int ft_uns_numb(unsigned int n, t_list *flags)
{
    int length;
    int count_space;
    char *s;

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
    s = ft_itoa(n);
    length = ft_strlen(s);
    ft_reduct(&s, flags, &length);
    free(s);
    return (length);
}