#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int x[41], n, tot = 0, ans = -1, half;
bool dp[801][801];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		tot += x[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1, half = tot >> 1;
	for(int i = 1; i <= n; i++)
		for(int j = half; j >= 0; j--)
			for(int k = j; k >= 0; k--)
				if (j >= x[i] && dp[j - x[i]][k] || k >= x[i] && dp[j][k - x[i]])
					dp[j][k] = 1;
	for(int i = half; i >= 1; i--)
		for(int j = i; j >= 1; j--)
			if (dp[i][j])
			{
				int k = tot - i - j;
				if (i + j > k && i + k > j && j + k > i)
				{
					double p = (i + j + k) * 1.0 / 2;
					int temp = (int)(sqrt(p * (p - i) * (p - j) * (p - k)) * 100);
					if (temp > ans)
						ans = temp;
				}
			}
	cout << ans << endl;
	return 0;
}
