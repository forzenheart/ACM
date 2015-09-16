#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int part[1000];


void calculate(const string &p)
{
	memset(part, 0, sizeof(part));
	int m = p.length();
	part[1] = 0;
	int k = 0;
	for(int q = 2; q < m; q++)
	{
		while( k > 0 && p[k + 1] != p[q])
		{
			k = part[k];
		}
		if(p[k + 1] == p[q])
			k = k + 1;
		part[q] = k;
	}
}

int next[10001];
char s[1000005];
char w[10005];

void Next(const char* b)
{
	int m = strlen(b);
	next[0] = next[1] = 0;
	int j = 0;
	for(int i = 1; i < m; i++)
	{
		while(j > 0 && b[i] != b[j])
			j = next[j];
		if(b[i] == b[j])
			j++;
		next[i + 1] = j;
	}
}
int KMP(const char* w, const char* s)
{
	int count = 0;
	int m = strlen(w);
	int n = strlen(s);
	Next(w);
	int q = 0;
	for(int i = 0; i < n; i++)
	{
		while(q > 0 && w[q] != s[i])
			q = next[q];
		if(w[q] == s[i])
			q++;
		if(q == m)
			count++;
	}
	return count;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%s%s", w, s);
		cout<<KMP(w, s)<<endl;
	}
}
