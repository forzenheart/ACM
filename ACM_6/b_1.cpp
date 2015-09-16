//注意cin的使用会超时
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 25e3+9;

bool use[maxn];

struct p{
	int a, b, c, d;
}data[maxn];

struct A{
	int key, down, up, id;
	bool operator < (const A& other) const
	{
		if(key == other.key) return down<other.down;
		return key < other.key;
	}
};

A a[maxn<<1];

int main()
{
	int T;

	while(scanf("%d", &T) != EOF)
	{
		for(int i=1;i<=T;i++)
		{
			scanf("%d %d",&data[i].a,&data[i].b);
			scanf("%d %d",&data[i].c,&data[i].d);
		}
		memset(use, 0, sizeof(use));
		//x轴扫描
		for(int i = 1; i <= T; i++)
		{
			a[i*2 - 1].key = data[i].a;
			a[i*2 - 1].down = data[i].b;
			a[i*2 - 1].up = data[i].d;
			a[i*2].key = data[i].c;
			a[i*2].down = data[i].b;
			a[i*2].up = data[i].d;
			a[i*2].id = a[i*2 - 1].id = i;
		}

		sort(a+1, a + T + T + 1);

		for(int i = 1, j; i <=T + T; i = j)
		{
			for(j = i; j <= T + T; j++)
				if(a[i].key != a[j].key)
					break;
			int up = a[i].up;
			for(int k = i + 1; k < j; k++)
			{
				if(a[k].down <= up)
					use[a[k].id] = use[a[k - 1].id] = 1;
				up = max(up, a[k].up);
			}
		}
		//y轴扫描
		for(int i = 1; i <= T;i++)
		{
			a[i*2 - 1].key = data[i].b;
			a[i*2 - 1].down = data[i].a;
			a[i*2 - 1].up = data[i].c;
			a[i*2].key = data[i].d;
			a[i*2].down = data[i].a;
			a[i*2].up = data[i].c;
			a[i*2].id = a[i*2 - 1].id = i;
		}

		sort(a+1, a + T + T + 1);

		for(int i = 1, j; i <=T + T; i = j)
		{
			for(j = i; j <= T + T; j++)
				if(a[i].key != a[j].key)
					break;
			int up = a[i].up;
			for(int k = i + 1; k < j; k++)
			{
				if(a[k].down <= up)
					use[a[k].id] = use[a[k - 1].id] = 1;
				up = max(up, a[k].up);
			}
		}
		int ans = 0;
		for(int i = 1; i <= T; i++)
			ans += !use[i];
		cout<<ans<<endl;
	}
	return 0;
}
