#include <iostream>
#include <cmath>
#include <cstring>

#define max 1000000000

using namespace std;

bool prime[max];

bool prime_2[max];

void find_prime()
{
	memset(prime_2, 0, sizeof(prime_2));

	for(int i = 0; i * i < max; i++)
	{
		if(!prime_2[i])
			for(int j = i * i; j < max; j+=i)
				prime_2[j] = true;
	}
}
void find_prime2()
{
	int sn = (int)sqrt(max);

	int half = max /2;

	for(int i = 0; i < half; i++)
		prime[i] = true;

	for(int i = 0; i * i < max; i++)
	{
		if(prime[i])
		{
			for(int k = i + i + 3, j = k * i + k + i; j < half; j+= k)
				prime[j] = false;
		}
	}

}
int main()
{

	//find_prime2();
	//for(int i = 0; i < 100; i++)
	//{
		//if(prime[i])
			//cout<<2 * i + 3<<endl;
	//}

	find_prime();
	for(int i = 0; i < max; i++)
		if(!prime_2[i])
			cout<<i<<endl;
	return 0;
}
