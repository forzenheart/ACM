#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int h, w;
int map[100][100];
int step;

class Point{
	public:
		int _x;
		int _y;
		Point(int x, int y):
			_x(x),
			_y(y)
	{}
};

Point direction[4] = {
	Point( 0, -1), //up
	Point(-1,  0), //left
	Point( 1,  0), //right
	Point( 0,  1)};//down

void DFS(int, int, int);
bool InMap(int x, int y)
{
	return ((x < h && x >= 0) && (y < w && y >= 0)) ? true : false;
}

void Find()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(map[i][j] == 2)
			{
				map[i][j] = 0;
				DFS(i, j, 1);
				return;
			}
		}
	}
}

void DFS(int x, int y, int now)
{
	int tx, ty;
	if (now > 10)
	{}
	else if(now < step)
	{
		for(int i = 0 ; i < 4; i++)
		{
			if(map[x + direction[i]._x][y + direction[i]._y] == 1)
				continue;
			tx = x;
			ty = y;
			while(InMap(tx + direction[i]._x, ty + direction[i]._y)
					&& map[tx + direction[i]._x][ty + direction[i]._y] == 0)
			{
				tx += direction[i]._x;
				ty += direction[i]._y;

			}
			if(map[tx + direction[i]._x][ty + direction[i]._y] == 3)
				step = now;
			else if(map[tx + direction[i]._x][ty + direction[i]._y] != 0)
			{
				map[tx + direction[i]._x][ty + direction[i]._y] = 0;
				DFS(tx, ty, now+1);
				map[tx + direction[i]._x][ty + direction[i]._y] = 1;
			}
		}
	}
}
int main()
{
	while(scanf("%d%d", &w, &h) &&( h != 0 && w != 0))
	{
		//Map Loading
		memset(map, 0, sizeof(map));
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				scanf("%d", &map[i][j]);
			}

		step = 11;

		Find();

		//out
		if(step <= 10)
			cout<<step<<endl;
		else
			cout<<-1<<endl;


	}
	return 0;
}
