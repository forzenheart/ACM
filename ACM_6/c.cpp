//No AC
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define INF 999999999.0

using namespace std;

struct Point{
	double x, y;
};

double tmX;
int bent;

int dep(double num)
{
	if(fabs(num) < 1e-12) return 0;
	return (num > 0) ? 1 : - 1;
}

double Area(Point p0, Point p1, Point p2)
{
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool intersect(Point A, Point B, Point C, Point D)
{
	double s1, s2;
	int d1, d2;
	s1 = Area(A, B, C);
	s2 = Area(A, B, D);
	d1 = dep(s1);
	d2 = dep(s2);
	if(d1 * d2 < 0)
	{
		tmX = (C.x * s2 - D.x*s1) / (s2 - s1);
		return true;
	}
	if(d1*d2 == 0) return true;
	return false;
}
int main()
{
	while(scanf("%d", &bent),bent)
	{
		vector<Point> up(bent);
		vector<Point> down(bent);

		for(int i = 0; i < bent; i++)
		{
			scanf("%lf %lf", &up[i].x, &up[i].y);
			down[i] = up[i];
			down[i].y--;
		}

		double TALL = -INF;
		tmX = -INF;

		for(int i = 0; i < bent; i++)
		{
			for(int j = 0; j < bent; j++)
			{
				int k = 0;
				while(k < bent)
				{
					if(!intersect(up[i], down[j], up[k], down[k])) break;
					k++;
				}
				if(k == bent)
					TALL = up[bent - 1].x;
				else if(k > max(i, j))
				{
					intersect(up[i], down[j], up[k - 1], up[k]);
					if(tmX>TALL)
						TALL = tmX;
					intersect(up[i], down[j],down[k - 1], down[k]);
					if(tmX > TALL)
						TALL = tmX;
				}
			}
		}
		if(TALL == up[bent - 1].x)
			cout<<"Through all the pepe."<<endl;
		else
			cout<<TALL<<endl;
	}

	return 0;
}
