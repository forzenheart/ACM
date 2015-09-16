#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int w[41];
int sum;
bool dp[801][801];

double s(int a, int b, int c)
{
	return 0.25 * sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
}

bool isTriangle(int a, int b, int c)
{
	if(a + b > c && a + c > b && b + c > a)
		return true;
	return false;
}


int main()
{
	int n;
	cin>>n;

	sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin>>w[i];
		sum += w[i];
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	int half = sum >> 1;
	for(int i = 1; i <= n; i++)
		for(int j = half; j >= 0; j--)
			for(int k = j; k >= 0; k--)
				if(j >= w[i] && dp[j - w[i]][k] || k >= w[i] && dp[j][k - w[i]])
					dp[j][k] = 1;


	int ans = -1;
	for(int i = half; i >= 1; i--)
		for(int j = i; j >= 1; j--)
			if(dp[i][j])
			{
				int k = sum - i - j;
				if(isTriangle(i, j, k))
				{
					int temp = (int)(s(i, j, k) * 100);
					if(temp > ans)
						ans = temp;
				}
			}
	cout<<ans<<endl;
	return 0;
}


//s =  1 / 4 * (sqrt((a + b + c) * (a + b - c) * (a + c - b) *  (b + c - a)));
//f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
// f[i][j] = max(f[i - 1][b + j][c], f[i - 1][b][c + j], f[i - 1][b][c])
//f[i][v][u] = max(f[i- 1][v][u], f[i - 1][v - Ci][u - Di] + s(a + w[i], b, c));
