#include <iostream>
#include <cmath>

using namespace std;

#define GodNum1 ((sqrt(5) + 1) / 2)

int main()
{
	int n, m;
	while(cin>>n)
	{
		cin>>m;
		if(n > m)
		{
			n = n ^ m;
			m = n ^ m;
			n = n ^ m;
		}

		int ak = (int)(m - n) * GodNum1;
		//如果是奇异局势，那么最小值一定为他们之间的差值乘以1.618
		if(n == ak)
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}


//娱乐用和本题无关， 计算一个数各个位数的和，直到和小于10；
int add(int x, int sum)
{
	if(x >= 10)
	{
		 sum += x % 10;
		 add(x / 10, sum);
	}
	else
	{
		 if(sum >= 10)
			 add(sum, 0);
		 else
			 return sum;
	}
}
