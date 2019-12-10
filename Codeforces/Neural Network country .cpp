#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int dp[mx][103],tmp;
short clc[1000007],a[103],v[103],ar[103],val[103],check[104];

int main()
{
    int n,l,m,x;
    scanf("%d %d %d", &n, &l, &m);
    mem(dp,-1);
    for(int i=1;i<=n;i++){ // 1
        scanf("%d",&x);
        //dp[1][x] = (dp[1][x]<0) ? 1 : dp[1][x]+1;
        clc[i] = x;
    }

    //2
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        ar[x]++;
    }
    int in=-1;
    for(int i=0;i<=100;i++){
        if(ar[i]>0){
            ar[++in] = ar[i];
            val[in] = i;
            //cout<<val[in]<<" x "<<ar[in]<<endl;
        }
    }
    //3
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        clc[i] += x;
    }
    for(int i=1;i<=n;i++){
        a[clc[i]%m]++;
    }
    int idx=-1;
    for(int i=0;i<=100;i++){
        if(a[i]>0){
            dp[1][i] = a[i];
            check[++idx] = i;
        }
    }
    //pnt
//    cout<<endl;
//    for(int i=1;i<=l+1;i++){
//        for(int j=0;j<=m;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    //
    int ix;
    for(int k=1;k<l;k++){

        for(int j=0;j<=m;j++){
            if(dp[k][j] != -1){
                for(int i=0;i<=in;i++){
                    ix = (j + val[i]) % m;

                    //dp[k+1][ix] = (dp[k][j] + ar[i]) % m;
                    tmp = (dp[k][j]==0) ? ar[i] : (dp[k][j] * ar[i]) ;
                    dp[k+1][ix] = (dp[k+1][ix] < 0) ? tmp : (dp[k+1][ix] + tmp);
                    dp[k+1][ix] %= mod;
                }
            }
        }

    }
    //
//    //int ix;
//    for(int k=1;k<l;k++){
//        for(int i=0;i<=in;i++){
//
//            for(int j=0;j<=m;j++){
//                if(dp[k][j] != -1){
//                    ix = (j + val[i]) % m;
//
//                    //dp[k+1][ix] = (dp[k][j] + ar[i]) % m;
//                    tmp = (dp[k][j]==0) ? ar[i] : (dp[k][j] * ar[i]) ;
//                    dp[k+1][ix] = (dp[k+1][ix] < 0) ? tmp : (dp[k+1][ix] + tmp);
//                    dp[k+1][ix] %= mod;
//                }
//            }
//        }
//    }
    // after last layer


//    for(int i=1;i<=in;i++){
//
//        for(int j=0;j<=m;j++){
//            if(dp[l][j] != -1){
//                ix = (j + val[i]) % m;
//                //dp[l+1][ix] = (dp[l][j] + ar[i]) % m;
//                tmp = (dp[l][j]==0) ? ar[i] : (dp[l][j] * ar[i]) % m;
//                dp[l+1][ix] = (dp[l+1][ix] < 0) ? tmp : (dp[l+1][ix] + tmp) % m;
//
//            }
//        }
//    }
//    cout<<endl;
//    for(int i=1;i<=l+1;i++){
//        for(int j=0;j<=m;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    cout<<dp[l][0]%mod <<endl;
}
