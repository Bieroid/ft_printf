#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int	indent;
	int	width;
	int	accur;
	int	dot;
	int	minus;
	int	null;
	int	prime_acc;
	int	real_acc;
}				t_list;

int		ft_printf(const char *format, ...);
void	ft_flags_zero(t_list **flags);
int		ft_indent(char const *format, int *i, t_list **flags);
int		ft_width(va_list *ap, char const *format, int *i);
int		ft_accur(va_list *ap, char const *format, int *i, t_list **flags);
int		ft_atoi(const char	*str);
int		ft_isdigit(int ch);
int		ft_search(char ch);
int		ft_putchar(char c);
int		ft_char(int c, t_list *flags);
int		ft_string(char *str, t_list *flags);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	ft_putstr(char *s);
int		ft_number(int n, t_list *flags);
int		ft_number_reduction(t_list *flags, int number);
int		ft_intlen(long int n);
void	ft_putnbr(long int n);
int		ft_uns_numb(unsigned int n, t_list *flags);
int		ft_pointer(size_t n, t_list *flags);
int		ft_pointer_norm(char **s, t_list *flags, int *length);
int		ft_hex(unsigned int n, t_list *flags, int rub);
int		ft_hex_norm(char **s, t_list *flags, int *length);

#endif