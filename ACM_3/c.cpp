#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 100000000
#define le 302
#define lne 50005
const int elem = 301;

typedef struct{
	int r,c,dis;
}re;
re q[le * le];

int der[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int vis[le][le];
int map[le][le];
int m;

void init(){
	int i,j;
	for(i = 0 ; i < le ; i++)
		for(j = 0 ; j < le ; j++)
			map[i][j] = INF;
}

void input(){
	int i,u,v,w;
	init();
	for(i = 0 ; i < m ; i++){
		scanf("%d%d%d",&u,&v,&w);
		if(w < map[u][v]) map[u][v] = w;
		if(u > 0){
			if(map[u-1][v] > w) map[u-1][v] = w;
		}
		if(map[u+1][v] > w) map[u+1][v] = w;
		if(v > 0){
			if(map[u][v-1] > w) map[u][v-1] = w;
		}
		if(map[u][v+1] > w) map[u][v+1] = w;
	}
}

int BFS(){
	int front = 0 , rear = 1 , i;
	re tem , g;
	if(map[0][0] == INF) return 0;
	if(map[0][0] == 0) return -1;
	memset(vis , 0 , sizeof(vis));
	tem.r = 0; tem.c = 0; tem.dis = 0;
	q[front] = tem;
	vis[0][0] = 0;
	while(front != rear){
		tem = q[front++];
		//if(front == lne) front = 0;
		for(i = 0 ; i < 4 ; i++){
			g.r = tem.r + der[i][0];
			g.c = tem.c + der[i][1];
			g.dis = tem.dis + 1;
			if(g.r >= 0 && g.r <= elem && g.c >= 0 && g.c <= elem)
				if(!vis[g.r][g.c] && map[g.r][g.c] > g.dis)
				{
					if(map[g.r][g.c] == INF){
						return g.dis;
					}
					vis[g.r][g.c] = 1;
					q[rear++] = g;
					//if(rear == lne) rear = 0;
				}
		}
	}
	return -1;
}

void deal(){
	int ans = BFS();
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&m) == 1){
		input();
		deal();
	}
	return 0;
}

