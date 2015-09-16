#include <iostream>
#include <algorithm>

using namespace std;

int a[12];
int b[12];

int main()
{
	int N, sum;
	cin>>N>>sum;

	for(int i = 1; i <= N; i++)
		a[i - 1] = i;

	do{

		for(int i = 0; i < N; i++)
			b[i] = a[i];
		int count = N - 1;
		while(count != 0)
		{
			for(int i = 0; i < count; i++)
				b[i] = b[i] + b[i + 1];
			count--;
		} 
		if(sum == b[0])
		{
			for(int i = 0; i < N; i++)
				cout<<a[i]<<" ";
			cout<<endl;
			break;
		}
	} while(next_permutation(a, a + N));
	
	return 0;
}
