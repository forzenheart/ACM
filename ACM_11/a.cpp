#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin>>T;

	string s, word;
	size_t pos = 0;
	int count = 0;
	while(T--)
	{
		cin>>word>>s;
		pos = 0;
		count = 0;
		pos = s.find(word);
		if(pos != string::npos)
			count++;

		//注意第二个参数pos为上一次发现的该字符串的位置，所以要 + 1从下一个位置开始查找
		while((pos = s.find(word, pos + 1)) != string::npos)
		{
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
