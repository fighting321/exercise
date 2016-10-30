#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#define ERROR -1
#define MAX_SIZE 1000


typedef int elem_type;

//top 可用不可取；取元素--top
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


//初始化栈 
LINK_STACK *init_linkstack();

//销毁栈 
bool destory_linkstack(LINK_STACK *p);

//判断是否为空栈 
bool is_empty(LINK_STACK *p);

//入栈 
bool push(LINK_STACK *p, elem_type e);

//出栈 
bool pop(LINK_STACK *p, elem_type *e);


#endif