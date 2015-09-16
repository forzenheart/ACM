//No AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 50005;

struct Point{
		int x; 
		int y;
};

Point p[N];
int top, n, s[N];

int Cross(Point a, Point b, Point c)//
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
int dis(Point a, Point b)
{
	return (a.x - b.x)*(a.x - b.x) + (a.y- b.y)*(a.y - b.y);
}

bool cmp(Point a, Point b)
{
	int ans = Cross(p[0], a, b);
	if(ans > 0 || ans == 0 && dis(p[0], a) > dis(p[0], b))
		return true;
	return false;
}

void Graham()//凸包模板
{
	s[0] = 0;
	s[1] = 1;
	top = 1;
	for(int i = 2; i < n; i++)
	{
		while(top && Cross(p[s[top - 1]], p[s[top]], p[i]) < 0)
			top--;
		s[++top] = i;
	}
	top++;
}

void RC()
{
	int q, ans = 0;

	q = 1; 
	ans = dis(p[s[0]], p[s[1]]);
	for(int i = 0; i != top; i++)
	{
		while(
				abs(Cross(p[s[(i + 1) % top]], p[s[i % top]], p[s[(q + 1) % top]]))  >
				abs(Cross(p[s[(i + 1) % top]], p[s[i % top]], p[s[q % top]]))
				)
			q = (q + 1) % top;
			ans = max(ans, max(dis(p[s[(i + 1) % top]], p[s[q]]), dis(p[s[i % top]], p[s[q]])));
	}
	printf("%d\n", ans);
}

int main()
{
	while(~scanf("%d", &n))
	{
		for(int i = 0; i < n; i++)
			scanf("%d %d", &p[i].x, &p[i].y);
		int u = 0;
		for(int i = 1; i !=n; i++)
		{
			if(p[u].y > p[i].y || p[u].y == p[i].y && p[u].x > p[i].x)
				u = i;
		}
		if(u)
		{
			swap(p[u].y, p[0].y);
			swap(p[u].x, p[0].x);
		}
		sort(p + 1, p + n, cmp);
		Graham();
		RC();
	}
	return 0;
}
