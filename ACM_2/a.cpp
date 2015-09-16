#include <iostream>

using namespace std;

void Hanno(char a, char b, char c, int num)
{
	if(num == 1)
	{
		cout<<a<<">"<<c<<endl;
	}
	if(num >= 1)
	{
		Hanno(a, c, b, num - 1);
		Hanno(a, b, c, num - 1);
		Hanno(c, b, a, num - 1);
	}
}




int main()
{
	int n;
	cin>>n;

	Hanno('A','B', 'C', n);

	return 0;
}
