#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	getchar();
	char str[2048];
	char dest[2048];
	char *p;
	while(n--)
	{
		fgets(str, 2048,stdin);
		p = str;

		while(*p != '\n')
		{
			cout<<*p++;
		}
	}

	return 0;
}
