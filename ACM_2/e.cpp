#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int h, w;
int ans;
char map[100][100];
char record[100][100];
class Point{
	public:
		Point(int x, int y)
			:
				_x(x),
				_y(y){}

		int _x;
		int _y;
};

Point direction[4] = {
	//Up
	Point( 0, -1),
	//Left
	Point(-1,  0), 
	//Right
	Point( 1,  0),
	//Down
	Point( 0,  1)};

bool InMap(int x, int y)
{
	return ((x < h && x >= 0) && (y < w && y>= 0)) ? true : false;
}

void DFS(int x, int y)
{
	if(!record[x][y] && map[x][y] == '.')
	{
		ans++;
		record[x][y] = 1;
	}
	else
		return;
	// scan: up left right down
	for(int i = 0; i < 4; i++)
	{
		if(InMap(x + direction[i]._x, y + direction[i]._y)
				&& !record[x + direction[i]._x][y + direction[i]._y]
				&& map[x + direction[i]._x][y + direction[i]._y] == '.')
		{
			DFS(x + direction[i]._x, y + direction[i]._y);
		}
	}
}

void Find()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(map[i][j] == '@')
			{
				map[i][j] = '.';
				DFS(i,j);
				return;
			}
		}
	}
}

int main()
{
	while(scanf("%d%d", &w, &h) && !(h == 0 && w == 0))
	{
		for(int i = 0; i < h; i++)
			scanf("%s", map[i]);
		memset(record, 0, sizeof(record));

		ans = 0;
		Find();
		cout<<ans<<endl;
	}
}
