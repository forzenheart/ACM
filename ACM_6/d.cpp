#include <cstdio>
#include <iostream>

using namespace std;

struct Node{
	double x, y;
};

int n;

double Arr[5][33], Area[33][33];
Node Point[33][33];

Node GetPoint(Node p1, Node p2, Node p3, Node p4)
{
	Node P;
	double A1 = p2.y - p1.y;
	double B1 = p1.x - p2.x;
	double C1 = p1.y*(p2.x - p1.x) - p1.x*(p2.y - p1.y);
	double A2 = p4.y - p3.y;
	double B2 = p3.x - p4.x;
	double C2 = p3.y*(p4.x - p3.x) - p3.x*(p4.y - p3.y);

	P.x = (C2*B1 - C1* B2) / (A1*B2 - A2*B1);
	P.y = (C2*A1 - C1* A2) / (B1*A2 - B2*A1);
	return P;
}

void GetPoints()
{
	//给四个角的点赋值
	Point[1][1].x = 0.0; Point[1][1].y = 0.0;
	Point[1][n + 2].x = 0.0; Point[1][n + 2].y = 1.0;
	Point[n + 2][1].x = 1.0; Point[n+2][1].y = 0.0;
	Point[n + 2][n + 2].x = 1.0; Point[n + 2][n + 2].y = 1.0;
	//给四条边上的点赋值
	for(int i = 2; i < n + 2; i++)
	{
		Point[1][i].x = 0.0; Point[1][i].y = Arr[3][i - 1];
		Point[n + 2][i].x = 1.0; Point[n + 2][i].y = Arr[4][i - 1];
		Point[i][1].x = Arr[1][i - 1]; Point[i][1].y = 0.0;
		Point[i][n + 2].x = Arr[2][i - 1]; Point[i][n + 2].y = 1.0;
	}

	for(int i = 2; i < n + 2; i++)
		for(int j  = 2; j< n+2; j++)
			Point[i][j] = GetPoint(Point[i][1], Point[i][n + 2], Point[1][j], Point[n + 2][j]);
}

//已知四点求四边形面积
double GetArea(Node p1, Node p2, Node p3, Node p4, int N)
{
	double area = 0;
	Node polygon[4];

	polygon[0] = p1;
	polygon[1] = p2;
	polygon[2] = p3;
	polygon[3] = p4;

	for(int i = 0, j; i < N; i++)
	{
		j = (i + 1) % N;
		area += polygon[i].x * polygon[j].y;
		area -= polygon[i].y * polygon[j].x;
	}
	area /= 2;
	return (area < 0 ? -area : area);
}

void GetAreas()
{
	int i , j;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= n + 1; j++)
			Area[i][j] = GetArea(Point[i][j], Point[i+1][j], Point[i+1][j + 1], Point[i][j + 1], 4);
}

double MaxArea()
{
	double ans = 0.0;
	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j <= n + 1; j++)
		{
			if(Area[i][j] >= ans)
				ans = Area[i][j];
		}
	}
	return ans;
}


int main()
{
	while(scanf("%d", &n), n)
	{
		for(int i = 1; i <= 4; i++)
			for(int j = 1; j <= n; j++)
				cin>>Arr[i][j];
		GetPoints();
		GetAreas();
		printf("%.6f\n", MaxArea());
	}
	return 0;
}
