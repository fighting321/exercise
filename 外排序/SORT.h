#ifndef _SORT_H_
#define _SORT_H_

#define MAX_SIZE 10000
#define ITEM_SIZE 500


void quick_sort(int *arr,int len);

void get_file_arr(char *path);

void quick_sort_file_arr(char *file_path,char *tmp_path);

void meger_file_arr();

void show_file_arr(char *path);

#endif