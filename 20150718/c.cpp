#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct hp
{
	int w[1005];
};

int main()
{
	char input_1[1000];
	char input_2[1000];

	scanf("%s", input_1);
	scanf("%s", input_2);

	int len_1 = strlen(input_1);
	int len_2 = strlen(input_2);
	hp a,b,c;
	memset(a.w, 0, sizeof(a.w));
	memset(b.w, 0, sizeof(b.w));
	memset(c.w, 0, sizeof(c.w));
	a.w[0] = len_1;
	b.w[0] = len_2;

	for(int i = len_1 - 1 ;i >= 0; i--)
	{
		a.w[len_1 - i] = input_1[i] - '0';
	}
	for(int i = len_2 - 1 ;i >= 0; i--)
	{
		b.w[len_2 - i] = input_2[i] - '0';
	}

	c.w[0] = a.w[0] + b.w[0] - 1;

	for(int i = 1; i <= a.w[0]; i++)
	{
		for(int j = 1; j <= b.w[0]; j++)
		{
			c.w[i + j - 1] += a.w[i] * b.w[j];
		}
	}

	for(int i = 1; i <= c.w[0]; i++)
	{
		if(c.w[i] >= 10)
		{
			c.w[i + 1] += c.w[i] / 10;
			c.w[i] %= 10;
		}
	}

	if(c.w[c.w[0] + 1] !=  0)
		c.w[0]++;

	for(int i = c.w[0]; i > 0; i--)
	{
		cout<<c.w[i];
	}
	cout<<endl;
	return 0;
}
