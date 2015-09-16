// No AC

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 316;

struct Point{
	Point()
	{}

	Point(double x, double y):
		_x(x), _y(y)
	{}

	double _x;
	double _y;
};

struct PolarAngle{
	double _angle;
	bool _flag;
	bool operator < (const PolarAngle& other)
	{
		return _angle < other._angle;
	}
};


Point ps[maxn];
PolarAngle as[maxn];

double distance(const Point& p1, const Point& p2)
{
	return sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
}

int solve(const int& n, const double &r)
{
	int maxPointNum = 0;
	//枚举所有的点
	for(int i = 0; i < n; i++)
	{
		int m  = 0;
		double d;

		//将每个点与它相交的圆弧找到
		//保存2个极点和角
		for(int j  = 0; j < n; j++)
		{
			if(i != j && (d = distance(ps[i], ps[j])) <= 2)
			{
				double phi = acos(d / 2);
				double theta = atan2(ps[j]._y - ps[i]._y, ps[j]._x - ps[j]._x);

				as[m]._angle = theta - phi;
				as[m++]._flag = true;
				as[m]._angle = theta + phi;
				as[m++]._flag = false;
			}
		}
		sort(as, as+m);
		for(int sum = 1, j = 0; j < m; ++j)
		{
			if(as[j]._flag)
				++sum;
			else
				--sum;
			maxPointNum = max(maxPointNum, sum);
		}
	}
	return maxPointNum;

}

int main()
{
	int N;
	while(cin>>N, N)
	{
		for(int i = 0; i < N; i++)
			cin>>ps[i]._x>>ps[i]._y;
		cout<<solve(N, 1.0)<<endl;
	}
	return 0;
}
