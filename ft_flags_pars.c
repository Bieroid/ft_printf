#include "ft_printf.h"

void ft_flags_zero(t_list **flags)
{
    (*flags)->accur = 0;
    (*flags)->indent = 0;
    (*flags)->width = 0;
    (*flags)->real_acc = 0;
}

int ft_indent(char const *format, int *i)
{
    int a;

    a = 0;
    if (format[*i] == '0')
        a = 1;
    while (format[*i] == '0' || format[*i] == '-')
    {
        if (format[*i] == '-')
            a = 2;
        *i = *i + 1;
    }
    return (a);
}

int ft_width(va_list *ap, char const *format, int *i)
{
    int a;

    if (format[*i] == '*')
    {
        a = va_arg(*ap, int);
        *i = *i + 1;
    }
    else
        a = ft_atoi(format + *i);
    while(ft_isdigit(format[*i]))
        *i = *i + 1;
    return (a);
}

int ft_accur(va_list *ap, char const *format, int *i)
{
    int a;

    if (format[*i] == '.')
        *i = *i + 1;
    else
        return (0);
    if (format[*i] == '*')
    {
        a = va_arg(*ap, int);
        *i = *i + 1;
    }
    else
        a = ft_atoi(format + *i);
    while (ft_isdigit(format[*i]))
        *i = *i + 1;
    if (a == 0)
        a = -1;
    return (a);    
}

void ft_checker(t_list **flags)
{
    if ((*flags)->width < 0)
    {
        (*flags)->width = (-1) * (*flags)->width;
        (*flags)->indent = 2;
    }
    if ((*flags)->accur < 0 && (*flags)->real_acc == 0)
        (*flags)->accur = 0;
}