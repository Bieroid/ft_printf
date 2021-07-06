#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

void	*ft_calloc(int num, int size)
{
	int	a;
	char	*s;

	a = 0;
	s = malloc(size * num);
	if (s == 0)
		return (0);
	while (a < (size * num))
	{
		s[a] = 0;
		a++;
	}
	return (s);
}

static char *ft_socr1(int len, char const *s, int start)
{
	int	a;
	char	*sub;

	a = 0;
	sub = ft_calloc(sizeof(char), len + 1);
	if (sub == 0)
		return (0);
	while (a < len)
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

static char *ft_socr2(int a, int start, char const *s)
{
	char	*sub;

	sub = ft_calloc(sizeof(char), (a - start) + 1);
	if (sub == 0)
		return (0);
	a = 0;
	while (s[start] != '\0')
	{
		sub[a] = s[start];
		a++;
		start++;
	}
	return (sub);
}

char	*ft_substr(char const *s, int start, int len)
{
	int	a;
	char	*sub;

	if (s == 0)
		return (0);
	a = ft_strlen(s);
	if (start > a)
	{
		sub = ft_calloc(sizeof(char), 1);
		if (sub == 0)
			return (0);
		return (sub);
	}
	if (a - start > len)
		sub = ft_socr1(len, s, start);
	else
		sub = ft_socr2(a, start, s);
	return (sub);
}
