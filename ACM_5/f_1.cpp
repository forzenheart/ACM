#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	while(cin >> n, n)
	{
		double a, b, num;
		if(n > 0)
		{
			for(int i = 32; i>=1; i--)
			{
				num = pow(n, 1.0/i);
				a = floor(num);
				b = ceil(num);
				if(fabs(num - a) < 1e-12 || fabs(b - num) < 1e-12)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		else
		{
			n = -n;

			for(int i = 32; i>=1; i--)
			{
				if(i % 2== 0) continue;
				num = pow(n, 1.0 / i);
				a = floor(num);
				b = ceil(num);
				if(fabs(a - num) < 1e-12 || fabs(b - num) < 1e-12) 
				{
					cout<<i<<endl;
					break;
				}
			}
		}

	}
	return 0;
}
