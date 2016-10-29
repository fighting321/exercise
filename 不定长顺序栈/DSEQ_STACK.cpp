#include "DSEQ_STACK.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>



//��ʼ��ջ 
DSEQ_STACK *init_dseqstack()
{
	DSEQ_STACK *p = (DSEQ_STACK *)malloc(sizeof(DSEQ_STACK));
	assert(p != NULL);

	p->data = (elem_type *)malloc(sizeof(elem_type) * MAX_SIZE);
	assert(p->data != NULL);

	p->top = 1;
	p->total_size = MAX_SIZE;

	return p;

}

//����ջ 
bool destory_dseqstack(DSEQ_STACK *p)
{
	if (p == NULL)
	{
		return false;
	}

	free(p->data);
	free(p);

	return true;
}

//�ж��Ƿ�Ϊ��ջ 
bool is_empty(DSEQ_STACK *p)
{
	return p->top == 0;
}

//����ջ�ռ�
bool inc(DSEQ_STACK *p)
{
	p->data = (elem_type *)realloc(p->data,sizeof(elem_type)* 2 * p->total_size);
	assert(p->data != NULL);

	printf("����: %d-%d\n",p->total_size,2*p->total_size);

	p->total_size = 2 * p->total_size;
	return true;

}

bool is_full(DSEQ_STACK *p)
{
	if (p == NULL)
	{
		return true;
	}

	return p->top == p->total_size;
}

//��ջ 
bool push(DSEQ_STACK *p, elem_type e)
{
	if (p == NULL) 
	{
		return false;
	}
	 
	if ( is_full(p))
	{
		inc(p);
	}

	p->data[p->top++] = e;
	
	return true;
}

//��ջ 
bool pop(DSEQ_STACK *p, elem_type *e)
{
	if (p == NULL || is_empty(p))
	{
		return false;
	}

	*e = p->data[--p->top];


	return true;
}
