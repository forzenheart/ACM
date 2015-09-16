#include <iostream>
#include <cstdio>

using namespace std;

void stack(int i)
{
	if(i >= 1)
	{
		stack(i - 1);
		cout<<" i = "<<i<<endl;
		stack(i - 1);
	}
}
int main()
{
	stack(3);
	return 0;
}
