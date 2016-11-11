#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SORT.h"


int main()
{
	get_file_arr("e:\\arr.txt");

	quick_sort_file_arr("e:\\arr.txt","e:\\tmp.txt");

	meger_file_arr();

	show_file_arr("e:\\arr.txt");

	return 0;
}