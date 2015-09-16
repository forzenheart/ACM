//仔细理会如何通过 2进制度优化的，这里不懂
#include <iostream>
#include <cstring>

using namespace std;

int n, c;
int v[1001];
int m[1001];
int f[100001];


int main()
{
	while(cin>>c>>n)
	{
		for(int i = 1; i <= n; i++)
			cin>>m[i]>>v[i];

		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
		{
			if(m[i] * v[i] > c)//当可拿物品的件数乘上它的体积大于背包体积则可以转换为完全背包问题
			{
				for(int j = v[i]; j <= c; j++)
					f[j] = max(f[j], f[j - v[i]] + v[i]);
			}
			else
			{
				int k = 1;
				while(k < m[i])
				{
					for(int j = c; j >= k * v[i]; j--)
						f[j] = max(f[j], f[j - k * v[i]] + k * v[i]);
					m[i] -= k;
					k <<= 1;
				}
				for(int j = c; j >= m[i] * v[i]; j--)//二进制剩余的数值
					f[j] = max(f[j], f[j - m[i] * v[i]] + m[i] * v[i]);
			}
		}
		cout<<f[c]<<endl;
	}
}
