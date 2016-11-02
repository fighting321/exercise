#include "LINK_SORT.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//初始化一个队列
LINK_SORT *init_queue()   
{
	LINK_SORT *p = (LINK_SORT *)malloc(sizeof(LINK_SORT));
	assert(p != NULL);
	p->data = 0;
	p->next = NULL;
	return p;
}
//销毁队列
bool destory_queue(LINK_SORT *phead)  
{
	if (phead == NULL)
	{
		return false;
	}

	LINK_SORT *p = phead->next;
	//释放队列中的元素
	while (p != NULL)
	{
		phead->next = p->next;
		free(p);
		p = phead->next;
	}

	free(phead);     //释放头结点
	return true;
}

//申请一个结点
static LINK_SORT *alloc_node(elem_type e)
{
	LINK_SORT *tmp = (LINK_SORT *)malloc(sizeof(LINK_SORT));
	assert(tmp != NULL);

	tmp->data = e;
	tmp->next = NULL;

	return tmp;
}

//判断队列是否为空
bool is_empty(LINK_SORT *phead)
{
	if (phead == NULL)
	{
		return false;
	}
	return phead->next == NULL;
}

//查看队列中的第一个元素，只是查看，并不出队列
bool get_head(LINK_SORT *phead, elem_type *e)
{
	if (phead == NULL)
	{
		return false;
	}
	*e = phead->next->data;
	return true;
}

//入队列
bool push(LINK_SORT *phead, elem_type e)
{
	if (phead == NULL)
	{
		return false;
	}

	LINK_SORT *p = phead;
	LINK_SORT *tmp = alloc_node(e);
	while(p->next != NULL)
	{
		p = p->next;
	}

	p->next = tmp;

	return true;

}

//出队列
bool pop(LINK_SORT *phead, elem_type *e)
{
	if (phead == NULL || is_empty(phead))
	{
		return false;
	}

	LINK_SORT *p = phead->next;

	phead->next = p->next;
	*e = p->data;
	free(p);
	return true;
}

//计算数组中最大元素的位数
int get_base(int *arr,int len)
{
	int max = arr[0];
	//求数组中的最大元素
	for (int i=1;i<len;i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int count = 0;
	
	// 计算最大元素的位数
	while(max != 0)
	{
		max /= 10;
		count++;
	}
	return count;
}

//排序
void base_sort(int *arr, int len, int base,int radix)
{
	LINK_SORT **bucket = (LINK_SORT **)malloc(sizeof(LINK_SORT *) * radix);//二级指针用来保存队列的地址
	assert(bucket != NULL);

	for (int i = 0;i<len;i++)
	{
		bucket[i] = init_queue();//以待排序数组的长度为标准初始化队列
	}

	for (int i = 0;i<base;i++)//遍历每个元素的每一位
	{
		for (int j = 0;j<len;j++)
		{
			//将数组中的元素逐一放进它第base位所对应的队列中
			push(bucket[(arr[j]/(int)pow((double)radix,i))%radix],arr[j]);
		}
		int k = 0;

		for (int j = 0;j<len;j++)
		{
			while(!is_empty(bucket[j]))//当队列不为空时，出队列，并继续放到数组中
			{
				pop(bucket[j],&arr[k]);	
				k++;

			}
		}
	}
	for (int i = 0;i<len;i++)
	{
		destory_queue(bucket[i]);
	}
	free(bucket);
} 
