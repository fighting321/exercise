#include "LINK_STACK.h"
#include <vld.h>


int main()
{
	LINK_STACK *p = init_linkstack();
	elem_type e;

	push(p,10);
	push(p,20);
	push(p,30);
	push(p,40);
	
	pop(p,&e);
	
	destory_linkstack(p);
	return 0;
}