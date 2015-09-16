#include <cstdio>

const int maxn = 1024;
int Stack[maxn];
int top = 0;
int B[maxn];//目标元素队列

int pop()
{
	if(top > 0)
		return Stack[--top];
}

void push(int t )
{
	Stack[top++] = t;
}

int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		while(scanf("%d", &B[0]), B[0])
		{
			top = 0;
			for(int i = 1; i < n; i++)
				scanf("%d", &B[i]);
			int pb = 0;
			int pa = 1;
			while(pb < n)
			{
				if(top > 0 && Stack[top - 1] == B[pb]) //栈不为空，如果栈顶等于目标元素，则弹出
				{
					pop();
					pb++;//目标位置加一，比较下一个目标
				}
				else
				{
					if(pa > n) //队列处理完毕
						break;
					push(pa++);//栈为空，或者栈顶不等于目标元素，则将队列元素压栈
				}
			}

			if(pb == n)//目标队列全部匹配，处理完毕
				printf("Yes\n");
			else//将队列元素检索完毕，仍然找不到匹配元素，则条件不成立
				printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
