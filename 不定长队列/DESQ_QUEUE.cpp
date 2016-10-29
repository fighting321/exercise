#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DSEQ_QUEUE.h"

DSEQ_QUEUQ *init_queue()
{
	DSEQ_QUEUQ *p = (DSEQ_QUEUQ *)malloc(sizeof(DSEQ_QUEUQ));
	assert(p != NULL);

	p->data = (elem_type *)malloc(sizeof(elem_type) * p->total_size);
	assert(p->data != NULL);

	p->head = 0;
	p->tail = 0;
	p->len = 0;
	p->total_size = MAX_SIZE;

	return p;
}


bool destory_queue(DSEQ_QUEUQ *p)
{
	if (p == NULL)
	{
		return false;
	}
	free(p->data);
	free(p);
	return true;
}

bool clear_queue(DSEQ_QUEUQ *p)
{
	if (p == NULL)
	{
		return false;
	}

	p->head = 0;
	p->tail = 0;
	return true;
}

DSEQ_QUEUQ *inc(DSEQ_QUEUQ *p)
{
	p->data = (elem_type *)realloc(p->data,sizeof(elem_type) * 2 * p->total_size);
	assert(p->data != NULL);

	printf("Ôö³¤%d-%d\n",p->total_size,2*p->total_size);
	p->total_size = 2 * p->total_size;

	return p;
}
bool is_empty(DSEQ_QUEUQ *p)
{
	if (p == NULL)
	{
		return false;
	}

	return p->head == p->tail;
}

bool is_full(DSEQ_QUEUQ *p)
{
	if (p == NULL)
	{
		return false;
	}

	return (p->tail+1)%MAX_SIZE == p->head;
}

bool get_head(DSEQ_QUEUQ *p, elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		return false;
	}

	*e = p->data[p->head];
	
	return true;
}

bool push(DSEQ_QUEUQ *p, elem_type e)
{
	if (p == NULL)
	{
		return false;
	}
	if (is_full(p))
	{
		inc(p);

		if (p->head != 0)
		{
			for (p->tail=0;p->tail<p->head -1;p->tail++)
			{
				p->data[p->len] = p->data[p->tail];
				p->len++;
			}
		}
		else
		{
			p->data[p->len] = p->data[p->tail];
			p->len++;
		}
	}

	p->data[(p->tail)%p->total_size] = e;
	p->tail++;
	p->len++;

	return true;
}

bool pop(DSEQ_QUEUQ *p,elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		return false;
	}
	
	
	*e = p->data[(p->head)%p->total_size];
	p->head++;
	p->len--;
	
	return true;
}

void show(DSEQ_QUEUQ *p)
{
	int i = p->head;
	while(i != p->tail)
	{
		printf("%d ",p->data[i]);
		i = (i + 1)%p->total_size;
	}

	printf("\n");
}



