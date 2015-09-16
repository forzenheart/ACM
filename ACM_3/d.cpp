#include <iostream>
#include <cstring>

using namespace std;

//有错误 当输入 3，5的时候步数错误。同理13 25；
//int Find_2(int f, int c)
//{
//	if(f >= c)
//		return f - c;
//	int count = 0;
//	int b_4 = 0;
//	int b_2 = 0;
//
//	if(f == 0)
//	{
//count++;
//		f = 1;
//	}
//	while(1)
//	{
//		if(c % 2)
//			count++;
//		c /= 2;
//		count++;
//		if(c < f)
//{
//			b_4 = c;
//			b_2 = c * 2;
//			break;
//		}
//}
//
//	if((f - b_4) > (b_2 - f))
//	{
//		count--;
//count += b_2 - f;
//}
//	else
//	{
//		count += f - b_4;
//}
//	return count;
//
//
//}

const int MAX = 1000024;
bool visit[MAX];
int FJ, cow;
int flag;
int step;
int head,tail;

class Point{
	public:
		int _x;
		int _d;
		Point()
		{}
		Point(int x, int d = 0)
			:
				_x(x),_d(d)
	{}
};

Point path[MAX];

bool InMap(int x)
{
	return (x <= 100000 && x >= 0) ? true : false;
}
void BFS(Point p)
{
	if(p._x == cow)
	{
		step = p._d;
		flag = true;
		return;
	}

	//suppose:
	//it`s can be changed by judege the double of the FJ, if FJ * 2 < CJ, just judge the FJ * 2,
	//not find (FJ - 1) and (F + 1);
	if(InMap(p._x + 1) && !visit[p._x + 1]) 
	{
		visit[p._x + 1] = true;
		Point n(p._x + 1, p._d + 1);
		path[tail++] = n;
	}
	if(InMap(p._x - 1) && !visit[p._x  - 1])
	{
		visit[p._x - 1] = true;
		Point pre(p._x - 1, p._d + 1);
		path[tail++] = pre;
	}
	if(InMap(p._x * 2) && !visit[p._x * 2])
	{
		visit[p._x * 2] = true;
		Point d(p._x * 2, p._d + 1);
		path[tail++] = d;
	}
}

int Find()
{
	if(FJ >= cow)
		return FJ - cow;
	head  = tail = 0;
	path[tail++] = Point(FJ, 0);
	flag = false;
	memset(visit, 0, sizeof(visit));
	visit[FJ] = 1;
	while(head < tail && !flag)
		BFS(path[head++]);
	return step;

}


int main()
{
	while(cin>>FJ>>cow)
	{
		cout<<Find()<<endl;
	}
	return 0;
}
