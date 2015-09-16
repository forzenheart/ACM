#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Point{
	public:
		int _x;
		int _y;
		int _z;
		int _d;
		char _m;
		Point()
		{}
		Point(int x, int y, int z, int d = -1, int m = 'n')
			:
				_x(x), _y(y),_z(z), _d(d), _m(m)
	{}
};


Point dir[6] = {
	Point(  1, 0, 0), Point( -1,  0,  0),
	Point(  0, 1, 0), Point(  0, -1,  0),
	Point(  0, 0, 1), Point(  0,  0, -1)
};

const int MAX = 100;
int L, R, C;
int head, tail;
int step;
bool flag;

Point map[MAX][MAX][MAX];
Point path[100000];
bool visit[50][50][50];

bool judge(int x, int y, int z)
{
	if(!(x >= 0 && x < C && y >= 0 && y < R && z >=0 && z < L))
		return false;
	if(map[x][y][z]._m == '#')
		return false;
	if(visit[x][y][z] == true)
		return false;
	return true;
}

void BFS(Point p)
{
	//如此标记有在第二层标记的时候有可能会重复将一个点加入队列；
	//visit[p._x][p._y][p._z] = true;
	if(map[p._x][p._y][p._z]._m == 'E')//将此条件放入循环中，如果起点和终点重合则找不到。
	{
		flag = true;
		step = p._d;
		return;
	}
	for(int i = 0; i < 6; i++)
	{
		if(judge(p._x + dir[i]._x, p._y + dir[i]._y, p._z + dir[i]._z))
		{
			Point _new(p._x + dir[i]._x, p._y + dir[i]._y, p._z + dir[i]._z, p._d + 1);
			path[tail++] = _new;
			visit[p._x + dir[i]._x][p._y + dir[i]._y][p._z + dir[i]._z] = true;
		}
	}
}
int Find(int x, int y, int z)
{
	flag = false;
	step = -1;
	head = tail = 0;
	path[tail++] = Point(x, y, z, 0);
	memset(visit, 0, sizeof(visit));
	while(head < tail && !flag)
	{
		BFS(path[head++]);
	}
	return step;
}

int main()
{
	while(cin>>L>>R>>C, !(L == 0 && R == 0 && C == 0))
	{
		int s_x = 0, s_y = 0, s_z = 0;
		for(int i = 0; i < L; i++)
		{
			for(int j = 0; j < R; j++)
			{
				for(int k = 0; k < C; k++)
				{
					cin>>map[k][j][i]._m;
					if(map[k][j][i]._m == 'S')
					{
						s_x = k;
						s_y = j;
						s_z = i;
					}
				}
			}
		}
		int ans;
		ans = Find(s_x, s_y, s_z);
		if(ans == -1)
			cout<<"Trapped!"<<endl;
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}
