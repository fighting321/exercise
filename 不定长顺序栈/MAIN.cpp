#include "DSEQ_STACK.h"
#include <stdio.h>


int main()
{
	DSEQ_STACK *p = init_dseqstack();
	push(p,1);
	push(p,2);
	push(p,3);
	push(p,4);
	push(p,5);

	return 0;
}