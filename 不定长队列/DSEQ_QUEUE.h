#ifndef _DSEQ_QUEUE_H_
#define _DSEQ_QUEUE_H_


#define ERROR -1
#define MAX_SIZE 10
typedef int elem_type;

typedef struct _DSEQ_QUEUQ
{
	elem_type *data;
	int head;
	int tail;
	int len;
	int total_size;

}DSEQ_QUEUQ;


DSEQ_QUEUQ *init_queue();
bool destory_queue(DSEQ_QUEUQ *p);
bool clear_queue(DSEQ_QUEUQ *p);

DSEQ_QUEUQ *inc(DSEQ_QUEUQ *p);
bool is_empty(DSEQ_QUEUQ *p);
bool is_full(DSEQ_QUEUQ *p);

bool get_head(DSEQ_QUEUQ *p, elem_type *e);
bool push(DSEQ_QUEUQ *p, elem_type e);
bool pop(DSEQ_QUEUQ *p, elem_type *e);

void show(DSEQ_QUEUQ *p);




#endif