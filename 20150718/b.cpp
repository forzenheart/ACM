#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct hp
{
	int w[1024];
};
int main()
{
	int n;
	cin>>n;
	char str_1[1024];
	char str_2[1024];
	int len_1 = 0, len_2 = 0;
	int p = 0;
	hp a,b,c;
	while(n--)
	{
		scanf("%s%s", str_1,str_2);
		len_1 = strlen(str_1);
		len_2 = strlen(str_2);
		memset(a.w, 0, sizeof(a.w));
		memset(b.w, 0, sizeof(b.w));
		memset(c.w, 0, sizeof(c.w));
		a.w[0] = len_1;
		b.w[0] = len_2;

		for(int i = 0; i < a.w[0]; i++)
			a.w[i + 1] = str_1[i] - '0';
		for(int i = 0; i < b.w[0]; i++)
			b.w[i + 1] = str_2[i] - '0';
		c.w[0] = a.w[0] > b.w[0] ? a.w[0] : b.w[0];

		for(int i = 1; i <= c.w[0]; i++)
			c.w[i] += a.w[i] + b.w[i];

		for(int i = 1; i <= c.w[0]; i++)
		{
			if(c.w[i] >= 10)
			{
				c.w[i] %= 10;
				c.w[i+1] += 1;
			}
		}

		if(c.w[c.w[0] + 1] !=  0)
			c.w[0]++;
		p = 0;
		for(int i = 1; i <= c.w[0]; i++)
		{
			if(c.w[i] == 0)
				continue;
			if(c.w[i] != 0)
			{
				p = i;
				break;
			}
		}
		for(int i = p; i <= c.w[0]; i++)
		{
			cout<<c.w[i];
		}
		cout<<endl;
	}
	return 0;
}
