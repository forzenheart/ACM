#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Point{
	public:
		Point(int x, int y)
		{
			_x = x;
			_y = y;
		}
		int _x;
		int _y;
};
int h, w;
int ans;

char map[100][100];
char record[100][100];

Point direction[8]  = {
	Point(-1, -1), Point(0,-1), Point(1,-1), 
	Point(-1,  0),				Point(1, 0), 
	Point(-1,  1), Point(0, 1), Point(1, 1)};

bool InMap(int x, int y)
{
	return ((x < h && x >= 0) && (y < w && y >= 0)) ? true : false;
}

void DFS(int x, int y);
void Find()
{
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
		{
			if(!record[i][j] && map[i][j] == 'W')
			{
				ans++;
				DFS(i, j);
			}
		}
}

void DFS(int x, int y)
{
	if(!record[x][y] && map[x][y] == 'W')
		record[x][y] = 1;
	else
		return;

	for(int i = 0; i < 8; i++)
	{
		if(InMap(x + direction[i]._x, y + direction[i]._y)
				&& !record[x+direction[i]._x][y + direction[i]._y]
				&& map[x + direction[i]._x][y + direction[i]._y] == 'W') 
		{
			DFS(x+direction[i]._x, y+direction[i]._y);
		}
	}
}

int main()
{

	scanf("%d%d",&h,&w);
	getchar();
	for(int i = 0; i < h; i++)
		scanf("%s", map[i]);

	ans = 0;
	memset(record, 0, sizeof(record));
	Find();
	cout<<ans<<endl;
	return 0;
}


