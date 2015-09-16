#include <iostream>
#include <cstring>

using namespace std;

int f[1001];
int v[1001];
int w[1001];
int n, c;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>c;
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			cin>>v[i];
		for(int i = 1; i <= n; i++)
			cin>>w[i];

		for(int i = 1; i <= n; i++)
			for(int j = c; j >= w[i]; j--)
				f[j] = max(f[j], f[j - w[i]] + v[i]);
		cout<<f[c]<<endl;
	}
}
