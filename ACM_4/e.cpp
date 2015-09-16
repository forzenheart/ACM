#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int map[6][6];
int ans;
int step;

pair<int, int> dir[4] = {
	make_pair( 0,  1),
	make_pair( 0, -1),
	make_pair( 1,  0),
	make_pair(-1,  0)
};

set<string> t;

bool InMap(int x, int y)
{
	return (0 <= x && x < 5 && 0 <= y && y < 5);
}

void DFS(int x, int y, string s)
{
	if(step == 5)
	{
		t.insert(s);	
		return;
	}

	for(int i = 0;i < 4; i++)
	{
		if(InMap(x + dir[i].first, y+dir[i].second))
		{
			step++;
			DFS(x + dir[i].first, y + dir[i].second, s + (char)map[x + dir[i].first][y + dir[i].second]);
			step--;
		}
	}

}
int main()
{
	ans = 0;
	step = 0;
	string s1;
	s1.clear();
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin>>map[i][j];

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			DFS(i, j, s1 + (char)map[i][j]);
	cout<<t.size()<<endl;

	return 0;
}
