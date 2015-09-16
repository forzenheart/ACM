#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int lines, rows;
int h, w;
bool success;
bool record[100][100];
int xx[30], yy[30];
class Point{
	public:
		int _x;
		int _y;
		Point(int x, int y):
			_x(x),_y(y) {}
};

Point direction[8] = {
	Point(-2, -1), Point(-2, 1),
	Point(-1, -2), Point(-1, 2), 
	Point( 1, -2), Point( 1, 2),
	Point( 2, -1), Point( 2, 1)};

bool InMap(int x, int y)
{
	return ((x <= rows && x >= 1) && (y <= lines && y >= 1)) ? true : false;
}

void DFS(int x, int y, int Num)
{
	xx[Num] = x;
	yy[Num] = y;
	if(Num == rows * lines)
	{
		success = true;
		return;
	}

	for(int i = 0; i < 8; i++)
	{
		if(InMap(x + direction[i]._x, y + direction[i]._y)
				&& !record[x + direction[i]._x][y + direction[i]._y]
				&& !success)
		{
			record[x+direction[i]._x][y+direction[i]._y] = 1;
			//path[stepNum++] = (x + direction[i]._x) * w + y + direction[i]._y;
			DFS(x+direction[i]._x, y+ direction[i]._y, Num + 1);
			record[x+direction[i]._x][y+direction[i]._y] = 0;
		}
	}
}


int main()
{
	int num;
	int count;
	cin>>num;

	count = 0;
	while(num--)
	{
		cin>>lines>>rows;
		success = false;
		memset(record, 0, sizeof(record));
		record[1][1] = 1;
		DFS(1,1,1);
		//Out
		cout<<"Scenario #"<<++count<<":"<<endl;
		if(!success)
			cout<<"impossible"<<endl;
		else
		{
			for(int k = 1; k <= rows * lines; k++)
				printf("%c%d", xx[k]+ 'A' - 1, yy[k]);
			cout<<endl;
		}
		if(num != 0)
			cout<<endl;
	}
}
