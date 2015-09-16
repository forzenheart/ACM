#include <iostream>
#include <cstring>

using namespace std;

int h, w;
int step;
char map[100][100];

class Point{
	public:
		int _x;
		int _y;
		int _d;
		Point(int x, int y, int z = -1)
			_x(x),
			_y(y),
			_d(z)
			{}

};

Point direction[4] = {
	Point( 0, -1),
	Point(-1,  0),
	Point( 1,  0),
	Point( 0,  1)};

bool InMap(int x, int y)
{
	return ((x < h && x >= 0) && (y < w && w >= 0)) ? true : false;
}

void BFS(int, int);
void Find()
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0 ; j < w; j++)
			if(map[i][j] == 'S')
				BFS(i, j);
	}
}

void BFS(int x, int y)
{

}
int main()
{
	cin>>h>>w;
	memset(map, 0, sizeof(map));
	for(int i = 0; i < h; i++)
		scanf("%s", map[i]);

	step = -1;
	Find();

	cout<<step<<endl;
	return 0;
}
