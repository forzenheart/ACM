#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1009;
const int INF=999999;
int a[maxn];
int t;
int n,q,l,r;
int main(){
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int ans=0;
            scanf("%d %d",&l,&r);
            for(int j=l-1;j<r;j++){
                ans=max(ans,a[j]);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
