#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vld.h>
#include "LINK_SORT.h"

int main()
{
	int arr[] = {278,109,63,930,589,184,505,269,8,83};
	int len = sizeof(arr)/sizeof(arr[0]);
	int base = get_base(arr,len);
	int radix = 10;

	base_sort(arr, len, base,radix);
	for (int i=0;i<len;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}