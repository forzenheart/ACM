#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int h, w;
int step;
bool flag;
char map[128][128];
bool visit[128][128];

class Point{
public:
	int _x;
	int _y;
	int _d;

	Point()
	{}
	Point(int x, int y, int z = -1):
		_x(x),_y(y),_d(z)
	{}
};

Point line[16384];
int head, tail;

Point direction[4] = {
	Point( 0, -1),
	Point(-1,  0),
	Point( 1,  0),
	Point( 0,  1)};

bool Judge(int x, int y)
{
	if(visit[x][y] == true) return false;
	if(map[x][y] == '*') return false;
	return ((x < h && x >= 0) && (y < w && y >= 0)) ? true : false;
}

void BFS(Point p)
{
	if(map[p._x][p._y] == 'T')
	{
		step = p._d;
		flag = true;
		return;
	}

	for(int i  = 0; i < 4; i++)
	{
		if(Judge(p._x + direction[i]._x, p._y + direction[i]._y))
		{
			Point _new(p._x + direction[i]._x, p._y + direction[i]._y, p._d + 1);
			line[tail++] = _new;
			visit[p._x + direction[i]._x][p._y + direction[i]._y] = true;
		}
	}
}
void Find()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if('S' == map[i][j])
			{
				Point s(i, j, 0);
				line[tail++] = s;
				break;
			}
		}
		if(tail)
			break;
	}
	while(head < tail && !flag)
		BFS(line[head++]);
}

int main()
{
	cin>>h>>w;
	memset(map, 0, sizeof(map));
	for(int i = 0; i < h; i++)
		scanf("%s", map[i]);

	step = -1;
	head = 0;
	tail = 0;
	flag = false;
	memset(visit, false, sizeof(visit));
	Find();

	cout<<step<<endl;
	return 0;
}
