#include "ft_printf.h"

static int ft_reduction(char **s, t_list *flags, int *length, int minus)
{
    int width;
    int count_zero;
    int rub;

    count_zero = 0;
    if (flags->accur >= *length)
        count_zero = flags->accur - *length + minus;
    if (flags->width >= flags->accur)
    {
        width = flags->width - count_zero - *length;
        rub = flags->width;
    }
    else
    {
        width = flags->accur - *length + minus;
        rub = flags->accur;
    }
    if (rub < *length || (flags->accur < 0 && flags->real_acc == 0))
    {
        if (minus == 1)
            ft_putchar('-');
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
        if (minus == 1)
            ft_putchar('-');
        while(count_zero-- > 0)
        {
            ft_putchar('0');
            *length = *length + 1;
        }
        ft_putstr(*s);
        return(0);
    }
    if (flags->indent == 1)
    {
        if (minus == 1)
            ft_putchar('-');
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
        if (minus == 1)
            ft_putchar('-');
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

int ft_number(int n, t_list *flags)
{
    int length;
    char *s;
    int minus;
    long int number;

    minus = 0;
    if (n < 0)
    {
        number = -n;
        minus = 1;
    }
    else
        number = n;
    if (n == -2147483648)
        number = 2147483648;
    if (n == 0 && flags->accur == -1)
    {
        length = 0;
        minus = flags->width;
        while (minus-- > 0)
        {
            ft_putchar(' ');
            length++;
        }
        return (length);
    }
    s = ft_itoa(number);
    length = ft_strlen(s) + minus;
    ft_reduction(&s, flags, &length, minus);
    free(s);
    return (length);
}