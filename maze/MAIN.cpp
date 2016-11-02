#include <stdlib.h>
#include <stdio.h>


void show(char s1[5][15])
{
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<14;j++)
		{
			printf("%c",s1[i][j]);
		}
		printf("\n");
	}
}

void maze(char s1[5][15],int x,int y)
{
	if (s1[x][y] == '1' || s1[x][y] == '#')
	{
		return;
	}
	if (s1[x][y] == '!')
	{
		printf("³ö¿ÚÎª%d,%d\n",x,y);
		exit(0);
	}
	if (s1[x][y] == '0')
	{
		s1[x][y] = '#';
		show(s1);
		printf("\n");
	}
	maze(s1,x,y-1);
	maze(s1,x-1,y);
	maze(s1,x,y+1);
	maze(s1,x+1,y);
}



int main()
{
	char s1[5][15] = 
	{
		"11111111111111",
		"10111111101111",
		"10111111101111",
		"100000000000!1",
		"11111111111111"
	};
	maze(s1,1,1);
	show(s1);
	return 0;
}