#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define max 30
int n;
int lines, rows;
int flag;
int mark[max][max];
int xx[30], yy[30];
int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int go(int xxx, int yyy)
{
	if(xxx >= 1 && xxx <= rows && yyy >= 1 && yyy <= lines)
	{
		return 1;
	}
	else
		return 0;

}
void dfs(int x, int y, int num)
{
	int xxx, yyy;
	xx[num] = x;
	yy[num] = y;
	if(num == lines * rows)
	{
		flag = 1;
		return ;
	}
	for(int h = 0; h < 8; h++)
	{
		xxx = x + dir[h][0];
		yyy = y + dir[h][1];
		if(go(xxx, yyy)&&!mark[xxx][yyy] && !flag)
		{
			mark[xxx][yyy] = 1;
			dfs(xxx, yyy, num +1);
			mark[xxx][yyy] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &lines, &rows);
		memset(mark, 0, sizeof(mark));
		mark[1][1] = 1;
		flag = 0;
		dfs(1, 1, 1);
		printf("Scenario #%d:\n",i);
		if(flag)
		{
			for(int k = 1; k <= lines * rows; k++)
			{
				printf("%c%d", xx[k]+ 'A' - 1, yy[k]);
			}
		}
		else
		{
			printf("impossible");
		}
		printf(i==n?"\n":"\n\n");
	}
	return 0;
}
