#include <iostream>

//Time Limit Exceed
//具体代码查看 f_1.cpp

using namespace std;

int main()
{
	int n;

	while(cin >> n, !(n == 0))
	{
		bool flag = true;
		for(int i = 2; i < n; i++)
		{
			if(n % i == 0)
			{
				int count = 1;
				int temp = i;

				while(1)
				{
					temp *= i;
					count++;
					if(temp >= n)
						break;
				}
				if(temp == n)
				{
					cout<<count<<endl;
					flag = false;
					break;
				}
			}
		}
		if(flag)
			cout<<"1"<<endl;
	}

	return 0;
}
