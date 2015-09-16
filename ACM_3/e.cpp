#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 1000000;
bool P[MAX];
int Prime[MAX];
int start, pos;
int head, tail;
bool visit[MAX];
bool flag;
int step;
int prime_num;


class Point{
	public:
		int _x;
		int _d;
		Point()
		{}
		Point(int x, int d = -1):
			_x(x), _d(d)
	{}
};

Point path[MAX];

void Prime_Find(int n, int m)
{
	memset(P, 0, sizeof(0));
	for(int i = 2; i*i <= 1000000; i++)
	{
		if(!P[i])
		{
			for(int j = i * i; j < 1000000; j+=i)
			{
				P[j] = true;
			}
		}
	}
	prime_num = 0;
	for(int i = n; i <= m; i++)
	{
		if(!P[i])
			Prime[prime_num++] = i;
	}
}

void BFS(Point);
void Find()
{
	head = tail = 0;
	memset(visit, 0, sizeof(visit));
	Point s(start, 0);
	path[tail++] = s;
	// WRONG!!
	for(int i = 0; i < prime_num; i++)
	{
		if(start == Prime[i])
			visit[i] = true;
	}
	flag = false;	
	step = 0;

	while(head < tail && !flag)
	{
		BFS(path[head++]);
	}

}


bool judge(int x, int y)
{
	int w[4], h[4];
	for(int i = 0; i < 4; i++)
	{
		w[i] = x % 10;
		h[i] = y % 10;
		x /= 10;
		y /= 10;
	}

	int eq = 0;
	for(int i = 0; i < 4; i++)
	{
		if(w[i] == h[i])
			eq++;
	}
	if(eq == 3)
		return true;
	else
		return false;
}

void BFS(Point p)
{
	if(p._x == pos)
	{
		flag = true;
		step = p._d;
		return;
	}

	for(int i = 0; i < prime_num; i++)
	{
		if(!visit[i] && judge(Prime[i], p._x))
		{
			visit[i] = true;
			Point _new(Prime[i], p._d + 1);
			path[tail++] = _new;
		}
	}

}




int main()
{

	Prime_Find(1000, 10000);

	int n;
	int count = 0;
	start = -1, pos = -1;
	cin>>n;
	while(1)
	{
		cin>>start>>pos;

		Find();
		cout<<step<<endl;

		count++;
		if(count == 100 || count == n)
			break;
	}
	return 0;	
}

