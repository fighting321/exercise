#include <stdio.h>
#include <vld.h>
#include "LINK_QUEUE.h"



int main()
{
	LINK_QUEUE *p = init_queue();
	for (int i = 0;i<10;i++)
	{
		push(p,i);
	}
	
	show(p);
	int tmp;
	for (int i = 0;i<2;i++)
	{
		pop(p,&tmp);
	}
	//pop(p,&tmp);
	show(p);
	destory_queue(p);
	return 0;
}