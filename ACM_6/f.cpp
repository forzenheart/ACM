//No AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define pi 3.141592653589
using namespace std;
typedef struct p
{
	int x;
	int y;
	double ji;
}vv;
vector <vv> a;
bool __inline cmp(vv p1,vv p2)
{

	if(p1.ji<p2.ji) return true;
	else if(p1.ji>p2.ji) return false;
	else if(p1.y<p2.y||(p1.y==p2.y&&p1.x<p2.x)) return true;
	else 
		return false;
};
int minn(vv *v,int n)
{
	int xm=10000000;
	int ym=10000000;
	int temp;
	for(int i=0;i<n;i++)
	{
		if(v[i].y<ym||(v[i].y==ym&&v[i].x<xm))
		{
			xm=v[i].x;
			ym=v[i].y;
			temp=i;
		}
	}
	return temp;
}
double des(int i ,int j)
{
	double x=a[i].x-a[j].x;
	double y=a[i].y-a[j].y;
	return x*x+y*y;
}


void mul(vv *v,int n)
{
	int temp;
	temp=minn(v,n);
	swap(v[n-1],v[temp]);
	for(int i=0;i<n-1;i++)
	{
		v[i].ji=atan2(double(v[i].y-v[n-1].y),double(v[i].x-v[n-1].x));
	}
	return ;
}
void gram(vv *v,int n)
{
	for(int i=2;i<n-1;i++)
	{
		bool index=true;
		while(index)
		{
			int ax,ay;
			int bx,by;
			int b=a.size();
			ax=v[i].x-a[b-2].x;
			ay=v[i].y-a[b-2].y;
			bx=a[b-1].x-a[b-2].x;
			by=a[b-1].y-a[b-2].y;
			if(ax*by-bx*ay>0&&a.size()>2)
			{
				a.pop_back();
			}
			else
			{
				a.push_back(v[i]);
				index=false;
			}
		}
	}
	return ;
}
int main()
{
	int n,lon;
	int ans;
	double tans;
	cin >>n>>lon;
	vv *v=new vv[n+1];
	for(int i=0;i<n;i++)
	{
		cin >>v[i].x>>v[i].y;
	}
	mul(v,n);
	sort(v,v+n-1,cmp);

	a.push_back(v[n-1]);
	a.push_back(v[0]);
	a.push_back(v[1]);
	gram(v,n);

	tans=0.0;

	for(int j=1;j<a.size();j++)
	{
		tans+=sqrt(des(j,j-1));
	}
	tans+=sqrt(des(a.size()-1,0));
	tans+=pi*2*lon;
	cout<<int(tans+0.5)<<endl;

	return 0;

}
