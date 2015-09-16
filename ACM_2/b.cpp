#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char map[100];
int n, k;
int num, ans;
int place[8];

void Find(int i)
{
	if(k == num)
	{
		ans++;
		return;
	}
	if(i >= n)
		return;
	for(int j  = 0; j < n; j++)
	{
		if(!place[j] && map[i * n +j] == '#')
		{
			place[j] = 1;
			num++;
			Find(i + 1);
			place[j] = 0;
			num--;
		}
	}
	Find(i + 1);
}
int main()
{
	while(scanf("%d%d", &n, &k) && !(n == -1 && k == -1))
	{
		for(int i = 0; i < n; i++)
			scanf("%s", &map[i * n]);
		memset(place, 0, sizeof(place));
		num = ans = 0;
		Find(0);
		cout<<ans<<endl;
	}

	return 0;
}
