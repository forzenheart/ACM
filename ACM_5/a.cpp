#include <iostream>

using namespace std;

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int n, m;
		cin>>n>>m;

		if(n % (m + 1) != 0)
			cout<<"first"<<endl;
		else
			cout<<"second"<<endl;
	}
	return 0;
}
