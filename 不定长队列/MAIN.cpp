#include <stdio.h>
#include <stdlib.h>
#include <vld.h>
#include "DSEQ_QUEUE.h"

int main()
{
	DSEQ_QUEUQ *p = init_queue();

	for (int i = 0;i<20;i++)
	{
		push(p,i);
	}
	
	show(p);

	int tmp;
	pop(p,&tmp);
	show(p);

	destory_queue(p);
	return 0;
}