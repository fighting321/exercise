#include "LINK_STACK.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//�������
static NODE *alloc_node(elem_type e)
{
	NODE *tmp = (NODE *)malloc(sizeof(NODE));
	assert(tmp != NULL);

	tmp->data = e;
	tmp->next = NULL;

	return tmp;
}
//��ʼ��ջ
LINK_STACK *init_linkstack()
{
	LINK_STACK *p = (LINK_STACK *)malloc(sizeof(LINK_STACK));
	assert(p != NULL);
    
	p->next = NULL;
	p->top = NULL;

	return p;
}

//����ջ 
bool destory_linkstack(LINK_STACK *p)
{
	if (p == NULL)
	{	
		return false;
	}
	elem_type e;

	while (p->top != NULL)
	{
		pop(p,&e);
	}

	free(p);
	return true;
}


//�ж��Ƿ�Ϊ��ջ 
bool is_empty(LINK_STACK *p)
{
	if (p == NULL)
	{
		return false;
	}

	return p->top == NULL;
}


//��ջ 
bool push(LINK_STACK *p, elem_type e)
{
	if (p == NULL)
	{
		return false;
	}

	NODE *tmp = alloc_node(e);
	
	tmp->next = p->top;
	p->next = tmp;
	p->top = tmp;

	return true;
}

//��ջ 
bool pop(LINK_STACK *p, elem_type *e)
{
	if(p == NULL || is_empty(p))
	{
		return false;
	}

	p->next = p->top->next;

	free(p->top);

	p->top = p->next;

	return true;
}



