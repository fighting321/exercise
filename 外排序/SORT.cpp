#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SORT.h"

static int partition(int *arr,int left,int right)
{

	int tmp = arr[left];

	while(left < right)
	{
		while(arr[right] >= tmp && left < right)
		{
			right--;
		}
		arr[left] = arr[right];
		while(arr[left] <= tmp && left < right)
		{
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = tmp;
	return left;
}

static void quick(int *arr,int left,int right)
{
	if (left < right)
	{
		int base = partition(arr,left,right);
		quick(arr,left,base-1);
		quick(arr,base+1,right);
	}
}

static void quick_sort(int *arr,int len)
{
	quick(arr,0,len-1);
}

void get_file_arr(char *path)
{
	FILE *fw = fopen(path,"wb");
	assert(fw != NULL);

	int *arr = (int *) malloc(sizeof(int) * ITEM_SIZE);
	assert(arr != NULL);

	srand(100);
	for (int i=0;i<MAX_SIZE;i++)
	{
		for (int j=0;j<ITEM_SIZE;j++)
		{
			arr[j] = rand()%MAX_SIZE;
		}
		 
		fwrite(arr,sizeof(arr),1,fw);
	}

	free(arr);
	fclose(fw);
}
void quick_sort_file_arr(char *file_path,char *tmp_path)
{
	FILE *fr = fopen(file_path,"rb");
	FILE *fw = fopen(tmp_path,"wb");
	assert(fr != NULL && fw != NULL);

	int *arr = (int *)malloc(sizeof(int) * ITEM_SIZE * 2);
	assert(arr != NULL);
	
	int num;

	while((num = fread(arr,sizeof(int),ITEM_SIZE*2,fr)) != 0)
	{
		quick_sort(arr,num);
		fwrite(arr,sizeof(int),num,fw);

	}
	
	fclose(fr);
	fclose(fw);
	free(arr);

	remove(file_path);
	rename(tmp_path, file_path); 
}

static void meger(char *arr_path,char *tmp_path,int gap)
{
	FILE *fr = fopen(arr_path,"rb");
	FILE *fw = fopen(tmp_path,"wb");
	assert(fr != NULL && fw != NULL);

	int *arr = (int *)malloc(sizeof(int) * ITEM_SIZE);
	int *brr = (int *)malloc(sizeof(int) * ITEM_SIZE);
	int *crr = (int *)malloc(sizeof(int) * ITEM_SIZE);
	assert(arr != NULL && brr != NULL && crr != NULL);

	int num = 0;

	int i = ITEM_SIZE;
	int j = ITEM_SIZE;
	int k = 0;
	int L1 = 0;
	int H1 = L1 + gap - 1;
	int L2 = H1 + 1;
	int H2 = L2 + gap - 1 > MAX_SIZE ? MAX_SIZE-1 : L2 + gap - 1; 

	while(L2 <MAX_SIZE)
	{
		while (L1 <= H1 && L2 <= H2)
		{
			if (i == ITEM_SIZE)
			{
				fseek(fr, L1*sizeof(int),SEEK_SET);
				fread(arr,sizeof(int),ITEM_SIZE,fr);
				i = 0;
			}
			if (j == ITEM_SIZE)
			{
				fseek(fr, L2*sizeof(int), SEEK_SET);
				fread(brr,sizeof(int),ITEM_SIZE,fr);
				j = 0;
			}
			if (arr[i] > brr[j])
			{
				crr[k++] = brr[j++];
				L2++;
			}
			else 
			{
				crr[k++] = arr[i++];
				L1++;
			}
			if (k == ITEM_SIZE)
			{
				fwrite(crr,sizeof(int),ITEM_SIZE,fw);
				k = 0;
			}
		}

		fwrite(crr,sizeof(int),k,fw);
		
		if(L1 <= H1)
		{
			fseek(fr, L1*sizeof(int),SEEK_SET);	
			fread(arr,sizeof(int),H1-L1+1,fr);
			fwrite(arr,sizeof(int),H1-L1+1,fw);			
		}	
	
		if(L2 <= H2)
		{
			fseek(fr, L2*sizeof(int),SEEK_SET);	
			fread(brr,sizeof(int),H2-L2+1,fr);
			
			fwrite(brr,sizeof(int),H2-L2+1,fw);
		}

		i = ITEM_SIZE;
		j = ITEM_SIZE;
		k = 0;
		L1 = H2 + 1;
		H1 = L1 + gap - 1;
		L2 = H1 + 1;
		H2 = L2 + gap - 1 > MAX_SIZE ? MAX_SIZE-1 : L2 + gap - 1;
	}
		
	if(L1 < MAX_SIZE)
	{
		num = MAX_SIZE-L1;
		while(num >= 0)
		{
			if(num < ITEM_SIZE)
			{
				fseek(fr,L1*sizeof(int),SEEK_SET);
				fread(arr,sizeof(int),num,fr);
				fwrite(arr,sizeof(int),num,fw);
				L1 = L1+num;
			}

			fseek(fr,L1*sizeof(int),SEEK_SET);
			fread(arr,sizeof(int),ITEM_SIZE,fr);
			fwrite(arr,sizeof(int),ITEM_SIZE,fw);
			L1 = L1+ITEM_SIZE;
			num = num - ITEM_SIZE;
		}

	}
	

	free(arr);
	free(brr);
	free(crr);

	fclose(fw);
	fclose(fr);

	remove(arr_path);
	rename(tmp_path, arr_path); 
	
}

void meger_file_arr()
{
	for (int i=ITEM_SIZE*2;i<MAX_SIZE;i=i*2)
	{
		meger("e:\\arr.txt","e:\\tmp.txt",i);
	}
}
void show_file_arr(char *path)
{
	FILE *fr = fopen(path,"rb");
	assert(fr != NULL);
	
	int tmp;
	int i = 0;
	while (fread(&tmp,sizeof(int),1,fr) != 0)
	{
		printf("%5d",tmp);
		if (i%5 == 4)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n");
	fclose(fr);
}