#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_

typedef int elem_type;

typedef struct _LINK_QUEUE
{
	struct _LINK_QUEUE *next;
	elem_type data;

}LINK_QUEUE;

LINK_QUEUE *init_queue();
bool destory_queue(LINK_QUEUE *phead);

bool is_empty(LINK_QUEUE *phead);

bool get_head(LINK_QUEUE *phead, elem_type *e);
bool push(LINK_QUEUE *phead, elem_type e);
bool pop(LINK_QUEUE *phead, elem_type *e);

void show(LINK_QUEUE *phead);

#endif