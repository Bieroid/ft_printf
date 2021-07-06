#include "ft_printf.h"
#include <limits.h>

int main()
{
    int i = ft_printf("m = [%.s]\n", "hello");
    int q = printf   ("o = [%.s]\n", "hello");
    printf("%d, %d\n", i, q);
	//system ("leaks a.out");
    return (0);
}