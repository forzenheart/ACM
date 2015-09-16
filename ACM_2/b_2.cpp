#include <iostream>

using namespace std;

void For(int i)
{
	if(i >= 5)
		return;
	cout<<i<<endl;
	For(i + 1);
}
int main()
{

	For(0);
	return 0;
}
