#include <stdio.h>
#include <ulimit.h>

int	main(void)
{
	printf("%ld", ulimit(UL_GETFSIZE));
}