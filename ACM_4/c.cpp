#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
int a[100];
int b[100];

int main()
{
	int T;
	cin>>T;
	getchar();

	string s;
	while(T--)
	{
		getline(cin, s);

		int count = 0;
		int result = 0;
		for(int i = 0; i < s.size(); i++)
			if(s[i] >= '0' && s[i] <= '9')
				a[count++] = s[i] - '0';

		sort(a, a + count);//注意排序，题目中并没有注明要排序;
		//数字个数为偶数个数，则选折差值最少的2个数作为最高位, 最高位大的数值尽量小，最高位小的数值尽量大

		if(count % 2 == 0)		{
			int mid = count / 2;
			int dv = 55;
			int first = 1;
			int minPos = 1;//为什么不可以是0 ，当输入2个数时候， 例如 0 1，结果为 0；
			if(a[0] == 0)
				first++;
			for(int i = first; i < count; i++)
			{
				if(dv > a[i] - a[i - 1])
				{
					dv = a[i] - a[i - 1];
					minPos = i;
				}
				else if(dv == a[i] - a[i - 1])//如果有多个数字之间的差值一样，则选折靠中间位置的2个数字
				{
					if(abs(minPos - mid) > abs(i - mid))
						minPos = i;
				}
			}

			int min = a[minPos];//minPos minvalue = 1; not 0!! waring!!
			int max = a[minPos - 1];//minPos must > 0;
			int bc = 0;
			for(int i  = 0; i < count; i++)
			{
				if(a[i] == min || a[i] == max)
					continue;
				b[bc++] = a[i];
			}
			for(int i = 0; i < bc / 2; i++ )
				min = min * 10 + b[i];

			for(int i = bc - 1; i >= bc / 2; i--)
				max = max * 10 + b[i];
			result = min - max;
		}
		else//奇数个数字，选择不是0的最小数值作为 位数多的首位，然位数多的数值尽量小。 剩下的数值尽量大差值就最小了;
		{
			int max = 0;
			int min = 0;
			if(count == 1)
				result = a[0];
			else
			{
				int	mid = (count + 1) / 2;
				if(a[0] == 0)
				{
					max = a[1] * 10;
					for(int i = 2; i < mid; i++)
						max = max * 10 + a[i];
					for(int i = count - 1; i >= mid; i--)
						min = min * 10 + a[i];
					result  = max - min;
				}
				else
				{
					for(int i = 0; i < mid; i++)
						max = max * 10 + a[i];
					for(int i = count - 1; i >= mid; i--)
						min = min * 10 + a[i];
					result  = max - min;
				}
			}
		}
		cout<<result<<endl;

	}
	return 0;
}

