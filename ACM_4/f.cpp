#include <iostream>
#include <cstdio>

using namespace std;

int a[1000000];
int b[1000000];
//打表思想
bool vis[1000000];

int main()
{
	int n, m;

	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		cin>>m;
		for(int i = 0; i < m; i++)
			scanf("%d", &b[i]);

		bool flag = true;
		int dvalue = 10000 + 40000;
		for(int i = 0; i < n; i++)
		{
			vis[50000 - a[i]] = true;
		}

		for(int i = 0; i < m; i++)
		{
			if(vis[b[i] + 40000] == true)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
