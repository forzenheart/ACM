#include<iostream>
#include <cstring>
#include<queue>
using namespace std;
#define M 100001
#define INF 10000000

struct POINT
{
	int pos;
	int step;
}now,next;
queue<POINT>Q;
bool visited[M];

int n,k;
int bfs()
{
	while(!Q.empty())
		Q.pop();
	now.pos=n;
	now.step=0;
	visited[now.pos]=true;
	Q.push(now);
	while(!Q.empty())
	{
		now=Q.front();
		Q.pop();
		next=now;
		for(int i=0;i<3;i++)
		{
			if(i==0) 
				next.pos=now.pos+1;
			if(i==1)
				next.pos=now.pos-1;
			if(i==2)
				next.pos=now.pos*2;
			next.step=now.step+1;
			if(next.pos==k)
				return next.step;
			if(next.pos<0||next.pos>M)
				continue;
			if(!visited[next.pos])
			{
				visited[next.pos]=true;
				Q.push(next);
			}
		}
	}
	return INF;
}

int main()
{
	while(cin>>n>>k)
	{
		memset(visited,false,sizeof(visited));
		if(n<k)
			cout<<bfs()<<endl;
		if(n==k)
			cout<<0<<endl;
		if(n>k)
			cout<<n-k<<endl;
	}
}
