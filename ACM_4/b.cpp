#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int mark[16];
bool vis[16];

int abs(int x)
{
	return (x < 0 ? -x : x);
}
int main()
{
	int T;
	cin>>T;
	getchar();

	while(T--)
	{
		memset(mark, 0, sizeof(mark));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < 3; i++)
		{
			string r, l, e;
			cin>>r>>l>>e;
			if(e[0] == 'e')
			{
				for(int j = 0; j < r.size(); j++)
				{
					vis[r[j] - 'A'] = 1;
					vis[l[j] - 'A'] = 1;
				}
			}
			else if(e[0] == 'u')
			{
				for(int j = 0; j < r.size(); j++)
				{
					mark[r[j] - 'A']++;
					mark[l[j] - 'A']--;
				}
			}
			else
			{
				for(int j = 0; j < r.size(); j++)
				{
					mark[r[j] - 'A']--;
					mark[l[j] - 'A']++;
				}
			}
		}

		int ans = 0, max = 0;
		for(int i = 0; i < 12; i++)
		{
			if(vis[i]) 
				mark[i] = 0;
			if(abs(mark[i]) > abs(max))
			{
				max = mark[i];
				ans = i;
			}
		}
		cout<<(char)('A' + ans)<<" is the counterfeit coin and it is "<<(max < 0 ? "light.": "heavy.")<<endl;
	}

	return 0;
}
