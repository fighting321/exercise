#include "LINK_SORT.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//��ʼ��һ������
LINK_SORT *init_queue()   
{
	LINK_SORT *p = (LINK_SORT *)malloc(sizeof(LINK_SORT));
	assert(p != NULL);
	p->data = 0;
	p->next = NULL;
	return p;
}
//���ٶ���
bool destory_queue(LINK_SORT *phead)  
{
	if (phead == NULL)
	{
		return false;
	}

	LINK_SORT *p = phead->next;
	//�ͷŶ����е�Ԫ��
	while (p != NULL)
	{
		phead->next = p->next;
		free(p);
		p = phead->next;
	}

	free(phead);     //�ͷ�ͷ���
	return true;
}

//����һ�����
static LINK_SORT *alloc_node(elem_type e)
{
	LINK_SORT *tmp = (LINK_SORT *)malloc(sizeof(LINK_SORT));
	assert(tmp != NULL);

	tmp->data = e;
	tmp->next = NULL;

	return tmp;
}

//�ж϶����Ƿ�Ϊ��
bool is_empty(LINK_SORT *phead)
{
	if (phead == NULL)
	{
		return false;
	}
	return phead->next == NULL;
}

//�鿴�����еĵ�һ��Ԫ�أ�ֻ�ǲ鿴������������
bool get_head(LINK_SORT *phead, elem_type *e)
{
	if (phead == NULL)
	{
		return false;
	}
	*e = phead->next->data;
	return true;
}

//�����
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

//������
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

//�������������Ԫ�ص�λ��
int get_base(int *arr,int len)
{
	int max = arr[0];
	//�������е����Ԫ��
	for (int i=1;i<len;i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int count = 0;
	
	// �������Ԫ�ص�λ��
	while(max != 0)
	{
		max /= 10;
		count++;
	}
	return count;
}

//����
void base_sort(int *arr, int len, int base,int radix)
{
	LINK_SORT **bucket = (LINK_SORT **)malloc(sizeof(LINK_SORT *) * radix);//����ָ������������еĵ�ַ
	assert(bucket != NULL);

	for (int i = 0;i<len;i++)
	{
		bucket[i] = init_queue();//�Դ���������ĳ���Ϊ��׼��ʼ������
	}

	for (int i = 0;i<base;i++)//����ÿ��Ԫ�ص�ÿһλ
	{
		for (int j = 0;j<len;j++)
		{
			//�������е�Ԫ����һ�Ž�����baseλ����Ӧ�Ķ�����
			push(bucket[(arr[j]/(int)pow((double)radix,i))%radix],arr[j]);
		}
		int k = 0;

		for (int j = 0;j<len;j++)
		{
			while(!is_empty(bucket[j]))//�����в�Ϊ��ʱ�������У��������ŵ�������
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
