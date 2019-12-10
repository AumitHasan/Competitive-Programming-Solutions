#include<bits/stdc++.h>
using namespace std;

int ar[103],dp[102][102][102];
int n,w,k,in;


int call(int i,int cnt,int mv)
{

    if(i>=in) return cnt;
    if(dp[i][cnt][mv] != -1) return dp[i][cnt][mv];

    int P = 0;

    P = max(P, call(i+1,cnt,mv));
    if(mv<k){
        int c=0;
        int h = ar[i] + w;
        for(int j=i;j<in;j++){
            if(ar[j]<=h) c++;
        }
        P = max(P, call(i+c,cnt+c,mv+1));
    }

    return dp[i][cnt][mv] = P;
}
int main()
{
    int T,N=0,x,y;
    scanf("%d",&T);

    while(++N<=T){
        in = 0;
        scanf("%d %d %d", &n, &w, &k);
        for(int i=0;i<n;i++){
            scanf("%d %d", &x, &ar[in++]);
        }
        sort(ar,ar+in);

        memset(dp,-1,sizeof(dp));
        int res = call(0,0,0);
        printf("Case %d: %d\n", N, res);
    }
    return 0;
}
