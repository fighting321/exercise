#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

#define ERROR -1
#define MAX_SIZE 10


typedef int elem_type;

//top 可用不可取；取元素--top

typedef struct _DSEQ_STACK
{	
	elem_type *data;
	int top;
	int total_size;
}DSEQ_STACK;


//初始化栈 
DSEQ_STACK *init_dseqstack();

//销毁栈 
bool destory_dseqstack(DSEQ_STACK *p);

//判断是否为空栈 
bool is_empty(DSEQ_STACK *p);

//入栈 
bool push(DSEQ_STACK *p, elem_type e);

//出栈 
bool pop(DSEQ_STACK *p, elem_type *e);

#endif