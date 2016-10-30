#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#define ERROR -1
#define MAX_SIZE 1000


typedef int elem_type;

//top ���ò���ȡ��ȡԪ��--top
typedef struct _NODE
{
	elem_type data;
	struct _NODE *next;

}NODE;
typedef struct _LINK_STACK
{	
	NODE *next;
	NODE *top;

}LINK_STACK;


//��ʼ��ջ 
LINK_STACK *init_linkstack();

//����ջ 
bool destory_linkstack(LINK_STACK *p);

//�ж��Ƿ�Ϊ��ջ 
bool is_empty(LINK_STACK *p);

//��ջ 
bool push(LINK_STACK *p, elem_type e);

//��ջ 
bool pop(LINK_STACK *p, elem_type *e);


#endif