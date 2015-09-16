#include <stdio.h>
#include <complex>
#define EPS (1e-8)
#define INF (1e300)
#define N (30)
#define MAX(x,y) (((x)>=EPS+(y))?(x):(y))
using std::complex;
typedef complex<double> POT;
int n;
POT up[N],bot[N];
double tmp;
double cross(POT a,POT b);
bool seginter(POT a,POT b,POT c,POT d);
int main()
{
	while (scanf("%d",&n),n)
	{
		for (int i=0;i<n;++i)
		{
			scanf("%lf%lf",&real(up[i]),&imag(up[i]));
			bot[i]=up[i];
			--imag(bot[i]);
		}
		double ans=-INF;
		for (int i=0;i<n;++i)
			for (int j=0;j<n;++j)
				if (i!=j)
				{
					int k;
					for (k=0;k<n&&seginter(up[i],bot[j],up[k],bot[k]);++k);
					if (k==n)
						ans=real(up[n-1]);
					else if (k>MAX(i,j))
					{
						if (seginter(up[i],bot[j],up[k-1],up[k]))
							ans=MAX(ans,tmp);
						if (seginter(up[i],bot[j],bot[k-1],bot[k]))
							ans=MAX(ans,tmp);
					}
				}
		if (fabs(ans-real(up[n-1]))<EPS)
			puts("Through all the pipe.");
		else
			printf("%.2f\n",ans);
	}
	return 0;
}
bool seginter(POT a,POT b,POT c,POT d)
{
	if (fabs(cross(b-a,d-c))<EPS)
		return false;
	double t=cross(b-a,a-c)/cross(b-a,d-c);
	if (t>=-EPS && t<=1+EPS)
	{
		tmp=real(c+t*(d-c));
		return true;
	}
	return false;
}
double cross(POT a,POT b)
{
	return imag(conj(a)*b);
}
