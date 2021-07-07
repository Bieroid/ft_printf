#include "ft_printf.h"

static t_list  *ft_parser(const char *format, int *i, va_list *ap)
{
    t_list  *flags;

    flags = malloc(sizeof(t_list));
    if (flags == 0)
        return (0);
    *i = *i + 1;
    ft_flags_zero(&flags);
    flags->indent = ft_indent(format, i, &flags);
    flags->width = ft_width(ap, format, i);
    flags->accur = ft_accur(ap, format, i, &flags);
    if (flags->width < 0)
    {
        flags->width = (-1) * flags->width;
        flags->indent = 2;
        flags->minus++;
        flags->null = 0;
    }
    return(flags);
}

static int ft_count_and_print(const char *format, int *i, t_list *flags, va_list *ap)
{
    int length;

    length = 0;
    if (format[*i] == '%')
        length = ft_char('%', flags);
    else if (format[*i] == 'c')
        length = ft_char(va_arg(*ap, int), flags);
    else if (format[*i] == 's')
        length = ft_string(va_arg(*ap, char*), flags);
    else if (format[*i] == 'p')
        length = ft_pointer(va_arg(*ap, size_t), flags);
    else if (format[*i] == 'd' || format[*i] == 'i')
        length = ft_number(va_arg(*ap, int), flags);
    else if (format[*i] == 'u')
        length = ft_uns_numb(va_arg(*ap, unsigned int), flags);
    else if (format[*i] == 'x')
        length = ft_hex(va_arg(*ap, unsigned int), flags, 0);
    else if (format[*i] == 'X')
        length = ft_hex(va_arg(*ap, unsigned int), flags, 1);
    free(flags);
    return (length);
}

static int ft_end(va_list ap, t_list *flags)
{
    va_end(ap);
    free(flags);
    return (-1);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    t_list  *flags;
    int     length;
    int     i;

    va_start(ap, format);
    i = -1;
    length = 0;
    while (format[++i] != '\0')
    {
        if (format[i] == '%')
        {
            flags = ft_parser(format, &i, &ap);
            if (flags == 0)
                return (-1);
            if (ft_search(format[i]))
                length = length + ft_count_and_print(format, &i, flags, &ap);
            else
                return (ft_end(ap, flags));
        }
        else
            length = length + ft_putchar(format[i]);
    }
    va_end(ap);
    return (length);
}
