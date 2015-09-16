#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	int n;
	cin>>T;
	vector<string> s;
	vector<string> order[10];

	int num = 0;
	while(T--)
	{
		cin>>n;
		s.clear();
		string input;
		for(int i = 0; i < n; i++)
		{
			cin>>input;
			s.push_back(input);
			order[i].clear();
		}

		int m;
		for(int i = 0; i < n; i++)
		{
			cin>>m;
			for(int j = 0; j < m; j++ )
			{
				cin>>input;
				order[i].push_back(input);
			}
		}

		bool flag = true;
		//注意排序，排列使用的是按字典序排列，不排序的话排列数目不正确;
		sort(s.begin(), s.end());
		bool alwaysWin = true;
		do{
			alwaysWin = true;
			sort(order, order + n);

			do{
				bool thisRoundWin = true;
				int armyNum = 0;
				for(int i = 0; i < n; i++)
				{
					thisRoundWin = true;
					string my = s[i];
					for(int k = armyNum; k < n; k++)
					{
						for(int j = 0; j < order[k].size(); j++)
						{
							string you = order[k][j];
							if(my == you)
							{
								thisRoundWin = false;
								break;
							}
						}
						if(thisRoundWin)
							armyNum++;
						else
							break;
					}
				}
				if(!thisRoundWin)
				{
					alwaysWin = false;
					break;
				}
			}while(next_permutation(order, order + n));

			if(alwaysWin)
			{
				flag = false;
				cout<<"Case "<<++num<<": Yes"<<endl;
				for(int i = 0; i < n - 1; i++)
					cout<<s[i]<<" ";
				cout<<s[n - 1]<<endl;
			}
		}while(flag && next_permutation(s.begin(), s.end()));

		if(flag)
			cout<<"Case "<<++num<<": No"<<endl;
	}
	return 0;
}
