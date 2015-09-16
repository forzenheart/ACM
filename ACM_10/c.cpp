#include <cstring>
#include <cstdio>

using namespace std;

int n, c;

struct Point{
	int _w;
	int _v;
	Point()
	{}
	Point(int w, int v)
		:
			_w(w), _v(v)
	{}
};

Point a[101];
int f[100005];

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{

	while(~scanf("%d", &n))
	{
		for(int i = 1; i <= n; i++)
			scanf("%d %d", &a[i]._v, &a[i]._w);
		scanf("%d", &c);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
		{
			for(int j = a[i]._w; j <= c; j++)
			{
					f[j] = max(f[j], f[j - a[i]._w] + a[i]._v);
			}
		}
		printf("%d\n", f[c]);
	}

}
