#include <iostream>

using namespace std;

int add(int x, int sum)
{
	if(x >= 10)
	{
		 sum += x % 10;
		 add(x / 10, sum);
	}
	else
	{
		sum += x;
		if(sum >= 10)
			add(sum, 0);
		else
			return sum;
	}
}

int main()
{

	while(1)
	{
		int input;
		cin>>input;
		cout<<add(input, 0)<<endl;
	}

	return 0;
}
