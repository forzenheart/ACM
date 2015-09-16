#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXT 1000000+5
#define MAXP 10000+5

using namespace std;

char T[MAXT], P[MAXP];
int f[MAXP], ans;

void getFail(char* P, int *f)
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i=1; i<m; i++)
	{
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i] == P[j] ? j+1 : 0;
	}
}

void find(char* T, char* P, int* f)
{
	int n = strlen(T), m = strlen(P);
	getFail(P, f);
	int j = 0;
	for (int i=0; i<n; i++)
	{
		while (j && P[j] != T[i]) j = f[j];
		if (P[j] == T[i]) j++;
		if (j == m)
		{
			ans++;
		}
	}
}


int main()
{
	int n;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		scanf("%s%s", P, T);
		ans = 0;
		find(T, P, f);
		cout<<ans<<endl;
	}
	return 0;
}
