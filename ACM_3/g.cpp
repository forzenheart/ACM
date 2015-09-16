#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=109;
int str[maxn][maxn];

int main(){
	int n,m;
	int sum;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&str[i][j]);
			}
		}
		sum=0;
		if(n%2!=0){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					sum=sum+str[i][j];
				}
			}
			printf("%d\n",sum);
			for(int i=0;i<n;i++){
				if(i%2==0){
					for(int j=1;j<m;j++){
						printf("R");
					}
				}
				if(i%2!=0){
					for(int j=1;j<m;j++){
						printf("L");
					}
				}
				if(i!=n-1)printf("D");
			}
			printf("\n");
		}else if(n%2==0&&m%2!=0){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					sum=sum+str[i][j];
				}
			}
			printf("%d\n",sum);
			for(int i=0;i<m-3;i++){
				if(i%2==0){
					for(int j=1;j<m;j++){
						printf("R");
					}
				}
				if(i%2!=0){
					for(int j=1;j<m;j++){
						printf("L");
					}
				}
				printf("D");
			}
			for(int i=0;i<m;i++){
				if(i%2==0){
					for(int j=0;j<1;j++){
						printf("D");
					}
				}
				if(i%2!=0){
					for(int j=0;j<1;j++){
						printf("U");
					}
				}
				if(i!=m-1)printf("R");
			}
			printf("\n");
		}else if(n%2==0&&m%2==0){


		}
	}
	return 0;
}
