#include <iostream>
#include <cstring>

using namespace std;

struct hp
{
	int w[500];
};

void fib(int n)
{
	if(n == 1 || n == 2)
		cout<<1<<endl;

	else
	{

		hp f0,f1,fn;
		memset(f0.w,0,sizeof(f0.w));
		memset(f1.w,0,sizeof(f1.w));
		memset(fn.w,0,sizeof(fn.w));

		f0.w[0] = 1;
		f1.w[0] = 1;

		f0.w[1] = 1;
		f1.w[1] = 1;

		for(int i = 2; i < n; i++)
		{
			fn.w[0] = f0.w[0] > f1.w[0] ? f0.w[0] : f1.w[0];

			for(int j = 1; j <= fn.w[0]; j++)
			{
				fn.w[j] = f0.w[j] + f1.w[j];
			}
			for(int j = 1; j <= fn.w[0]; j++)
			{
				if(fn.w[j] >= 10)
				{
					fn.w[j] %= 10;
					fn.w[j+1] += 1;
				}

			}
			if(fn.w[fn.w[0] + 1] != 0)
				fn.w[0]++;
			f0 = f1;
			f1 = fn;
		}

		for(int i = fn.w[0]; i > 0; i--)
		{
			cout<<fn.w[i];
		}
		cout<<endl;
	}
}

int main()
{

	int n;
	int input;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin>>input;
		fib(input);
	}

	return 0;
}
