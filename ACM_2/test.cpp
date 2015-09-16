#include <iostream>

using namespace std;

int k,n,num;

void stack(int i)
{
	if(i >= 0)
	{
		stack(i - 1);
		cout<<"i = "<<i<<endl;
	}

}

void hanno(int i)
{
	if(i >= 0)
	{
		hanno(i - 1);
		cout<<"i = "<<i<<endl;
		hanno(i - 1);
	}
}

void DFS(int i)
{
	if(i >= 5)
		return;
	for(int j = 0; j < 5; j++)
	{
		cout<<i<<" , "<<j<<endl;
		DFS(i + 1);
	}
}
int main()
{
	//stack(10);
	//hanno(5);
	DFS(0);
	return 0;
}
