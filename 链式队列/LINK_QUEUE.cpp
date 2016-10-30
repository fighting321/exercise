#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LINK_QUEUE.h"


LINK_QUEUE *init_queue()
{
	 LINK_QUEUE *p = (LINK_QUEUE *)malloc(sizeof(LINK_QUEUE));
	 assert(p != NULL);
	 p->data = 0;
	 p->next = NULL;
	 return p;
}
bool destory_queue(LINK_QUEUE *phead)
{
	if (phead == NULL)
	{
		return false;
	}

	LINK_QUEUE *p = phead->next;
	while (p != NULL)
	{
		phead->next = p->next;
		free(p);
		p = phead->next;
	}
	free(phead);
	return true;
}


static LINK_QUEUE *alloc_node(elem_type e)
{
	LINK_QUEUE *tmp = (LINK_QUEUE *)malloc(sizeof(LINK_QUEUE));
	assert(tmp != NULL);

	tmp->data = e;
	tmp->next = NULL;

	return tmp;
}
bool is_empty(LINK_QUEUE *phead)
{
	if (phead == NULL)
	{
		return false;
	}
	return phead->next == NULL;
}

bool get_head(LINK_QUEUE *phead, elem_type *e)
{
	if (phead == NULL)
	{
		return false;
	}
	 *e = phead->next->data;
	 return true;
}
bool push(LINK_QUEUE *phead, elem_type e)
{
	if (phead == NULL)
	{
		return false;
	}

	LINK_QUEUE *p = phead;
	LINK_QUEUE *tmp = alloc_node(e);
	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = tmp;

	return true;

}
bool pop(LINK_QUEUE *phead, elem_type *e)
{
	if (phead == NULL || is_empty(phead))
	{
		return false;
	}

	LINK_QUEUE *p = phead->next;

	phead->next = p->next;
	free(p);
	return true;
}

void show(LINK_QUEUE *phead)
{
	LINK_QUEUE *p = phead->next;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}