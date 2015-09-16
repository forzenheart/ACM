#include<stdio.h>
#include<cstring>
const int MAX_N = 11;
const int MAX_M = 100008;
int N,M;
int dp[MAX_M];
struct Money
{
	int val;
	int k;
}money[MAX_N];
void Init()
{
	memset(dp,0,sizeof(dp));
}
void Dp()
{
	int i,j,k,tmp;
	bool done;
	for(i=0;i<N;i++)
	{
		for(k=1;;k<<=1)
		{
			done = true;
			if(money[i].k-k>=0)
			{
				money[i].k-=k;
				done =  false;
			}
			else
			{
				k=money[i].k;
			}
			for(j=M;k>=0&&j>=money[i].val*k;j--)
			{
				tmp=j-money[i].val*k;
				if(tmp>=0)
				{
					if(dp[j]<dp[tmp]+money[i].val*k)
					{
						dp[j]=dp[tmp]+money[i].val*k;
					}
				}
			}
			if(done)break;
		}
	}
}
void Run()
{
	Init();
	Dp();
	printf("%d\n",dp[M]);
}
int main()
{
	int i;
	while(scanf("%d",&M)!=EOF)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&money[i].k,&money[i].val);
		}
		Run();
	}
	return 0;
}
