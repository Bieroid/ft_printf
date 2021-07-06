#include "ft_printf.h"
#include <limits.h>

int main()
{
    int i = ft_printf("m = [st8 %*.*s\n]\n", 0, 0, "coucou");
    int q = printf   ("o = [st8 %*.*s\n]\n", 0, 0, "coucou");
    printf("%d, %d\n", i, q);
	//system ("leaks a.out");
    return (0);
}