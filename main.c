#include <stdio.h>
#include "limits.h"
int main()
{
	int j = INT_MAX;
	long i = LONG_MAX;
	long long int k = 9223372036854775807;

	printf("int:%d\nlong:%ld\nLLONG:%lld", j, i, k);
	return 0;
}
