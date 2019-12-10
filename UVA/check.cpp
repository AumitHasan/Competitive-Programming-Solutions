#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define PB push_back
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

llu n,m,A[51],in,dp[51][51][101],take,ar[51];
//vector<llu>ar;

llu call(int i,int totl,int t)
{
    if(totl==take) return 1;
    if(i>=in){
        return 0;
    }
    if(dp[i][totl][t]!=-1) return dp[i][totl][t];

    llu P = 0;

    for(int j=0;j<=ar[i];j++){
        if(totl+j<=take) P += call(i+1,totl+j,t);
    }

    return dp[i][totl][t] = P;
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");

    int test=0,x;
    while(scanf("%llu%llu",&n,&m)){
        if(!n) break;
        mem(A,0);
        mem(ar,0);

        for(int i=0;i<n;i++){
            scanf("%llu",&x);
            A[x]++;
        }
        in = 0;
        for(int i=0;i<=n;i++){
            if(A[i]>0){

                ar[in++] = A[i];
            }
        }
        printf("Case %d:\n",++test);
        mem(dp,-1);
        for(int i=0;i<m;i++){
            scanf("%llu",&take);
            //mem(dp,0);
            llu res = call(0,0,i);
            //if(take>0) res--;
            printf("%llu\n",res);
        }
    }
    return 0;
}
