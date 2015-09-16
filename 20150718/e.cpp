#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct hp
{
	int w[8001];
};

hp multiplication(hp a, hp b)
{

	hp c;
	memset(c.w, 0, sizeof(c.w));

	c.w[0] = a.w[0] + b.w[0] - 1; 

	for(int i = 1; i <= a.w[0]; i++)
	{
		c.w[i] += a.w[i] * b.w[1];
	}

	for(int i = 1; i <= c.w[0]; i++)
	{
		if(c.w[i] >= 100000)
		{
			c.w[i+1] += c.w[i] / 100000;
			c.w[i] %= 100000;
		}
	}

	if(c.w[c.w[0] + 1] != 0)
		c.w[0]++;

	return c;

}
void factorial(int n)
{
	hp fn,count;

	memset(fn.w, 0, sizeof(fn.w));
	memset(count.w, 0, sizeof(count.w));
	fn.w[0] = 1;
	fn.w[1] = 1;
	count.w[0] = 1;
	count.w[1] = 1;

	int temp;
	for(int i = 1; i <= n; i++)
	{
		fn = multiplication(fn, count);
		count.w[1]++;
	}

	for(int i = fn.w[0]; i > 0; i--)
	{
		if(i == fn.w[0])
			cout<<fn.w[i];
		else
		{
			printf("%05d",fn.w[i]);
		}
	}
	cout<<endl;
}

int main()
{

	int n;
	while(cin>>n)
		factorial(n);
	return 0;
}
