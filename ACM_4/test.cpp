#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	char s[55];
	int a[15];
	int b[15];
	int T,n,m,i,j,x,y,ans,k;
	scanf("%d",&T);
	gets(s);
	while(T--)
	{
		gets(s);
		int num=0;
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]>='0'&&s[i]<='9')a[num++]=s[i]-'0';
		}
		sort(a,a+num);
		if(num%2==0)
		{
			k=num/2;
			i=1;
			int tem=55,c=1;
			if(a[0]==0)i=2;
			for(i=i;i<num;i++)
			{
				if(tem>a[i]-a[i-1])
				{
					tem=a[i]-a[i-1];
					c=i;
				}
				else if(tem==a[i]-a[i-1])
				{
					if(abs(c-k)>abs(i-k))c=i;
				}
			}
			x=a[c];y=a[c-1];
			j=0;
			for(i=0;i<num;i++)
			{
				if(a[i]==x||a[i]==y)continue;
				b[j++]=a[i];
			}
			k=(num-2)/2;
			for(i=0;i<k;i++)
				x=x*10+b[i];
			for(i=num-3;i>=k;i--)
				y=y*10+b[i];
			ans=x-y;
		}
		else
		{
			if(num==1)ans=a[0];
			else
			{
				k=(num+1)/2;
				if(a[0]==0)
				{
					x=a[1]*10;
					for(i=2;i<k;i++)
						x=x*10+a[i];
					y=0;
					for(i=num-1;i>=k;i--)
						y=y*10+a[i];
					ans=x-y;
				}
				else
				{
					x=0;
					for(i=0;i<k;i++)
						x=x*10+a[i];
					y=0;
					for(i=num-1;i>=k;i--)
						y=y*10+a[i];
					ans=x-y;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
