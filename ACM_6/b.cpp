// No AC
//
#include <iostream>
#include <vector>

using namespace std;

struct Rectange{
	int l_x1, _ly1;
	int l_x2, l_y2;
	int r_x1, r_y1;
	int r_x2, r_y2;

	bool type1, type2, type3, type4;

	int _id;
	bool _type;

	Rectange()
	{}

	Rectange(
			int left_x1, int left_y1, bool type1, 
			int left_x2, int left_y2, bool type2,
			int right_x1, int right_y1, bool type3,
			int right_x2, int right_y2, bool type4)
		:
			_x1(x1),
			_y1(y1),
			_x2(x2),
			_y2(y2),
	{}
};


vector<Rectange> v;

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		v.push_back(Rectange(x1, y1, x2, y2));

		for(int i = 0; i < v.size(); i++)
		{

		}
	}
	return 0;
}	
