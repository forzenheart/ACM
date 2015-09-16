#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1000000;

int Prime[MAX];
bool Mark[MAX];
int prime_num;

bool judge(int , int);
void Find_Prime(int x, int y, int n)
{
	for(int i = 2; i * i <= 1000000; i++)
	{
		if(!Mark[i])
		{
			for(int j = i * i; j <= 1000000; j += i)
			{
				Mark[j] = 1;
			}
		}
	}
	prime_num = 0;

	for(int i = x; i <= y; i++)
	{
		if(!Mark[i])
			Prime[prime_num++] = i;
	}

	for(int i = 0 ; i < prime_num; i++)
	{
		if(judge(Prime[i], n))
			cout<<Prime[i]<<endl;
	}

}

bool judge(int x, int n)
{
	int w[4];
	bool flag = false;
	for(int i = 0; i < 4; i++)
	{
		w[i] = x % 10;
		x /= 10;
		if(w[i] == n)
			flag = true;
	}
	return flag;
}

int main()
{
	int n;
	cin>>n;

	Find_Prime(1000, 9999, n);
	return 0;
}
