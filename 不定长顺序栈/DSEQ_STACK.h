#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

#define ERROR -1
#define MAX_SIZE 10


typedef int elem_type;

//top ���ò���ȡ��ȡԪ��--top

typedef struct _DSEQ_STACK
{	
	elem_type *data;
	int top;
	int total_size;
}DSEQ_STACK;


//��ʼ��ջ 
DSEQ_STACK *init_dseqstack();

//����ջ 
bool destory_dseqstack(DSEQ_STACK *p);

//�ж��Ƿ�Ϊ��ջ 
bool is_empty(DSEQ_STACK *p);

//��ջ 
bool push(DSEQ_STACK *p, elem_type e);

//��ջ 
bool pop(DSEQ_STACK *p, elem_type *e);

#endif