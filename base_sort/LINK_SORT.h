#ifndef _LINK_SORT_H_
#define _LINK_SORT_H_


#define MAX_SIZE 100
#define ERROR -1


typedef int elem_type;

typedef struct _LINK_SORT
{
	elem_type data;
	struct _LINK_SORT *next;
	
}LINK_SORT;


LINK_SORT *init_queue();
bool destory_queue(LINK_SORT *p);
bool clear_queue(LINK_SORT *p);


bool is_empty(LINK_SORT *p);
bool is_full(LINK_SORT *p);

bool push(LINK_SORT *p, elem_type e);
bool pop(LINK_SORT *p, elem_type *e);

int get_base(int *arr,int len);
void base_sort(int *arr, int len, int base,int radix);

void destory_sort(LINK_SORT *phead);


#endif