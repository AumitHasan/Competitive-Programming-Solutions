#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 207

ll dp[mx][mx];
int N,M,K,D;

ll bi(int n, int r){

    if(r>n || n==r || r==0) return 1;

    if(dp[n][r] != -1) return dp[n][r];

    dp[n][r] = (bi(n-1,r-1)%mod + bi(n-1,r)%mod) %mod;

    return dp[n][r];
}
int main()
{
    mem(dp,-1);
    //
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&N, &M, &K, &D);
        int a=0,b=0,tmp;
        for(int i=0;i<N;i++){
            scanf("%d",&tmp);
            if(tmp >= D) a++;
            else b++;
        }
        if(a<K){
            printf("1\n");
            continue;
        }
        //
        ll val,ans = bi(N,M);
        //cout<<ans<<" "<<a<<" "<<b<<endl;
        for(int i=0;i<K;i++){
            if(M-i <= b){
                val = bi(a,i)%mod * bi(b,M-i)%mod;
                val %= mod;
                ans -= val;
                if(ans<0){
                    ans = (ans+mod) % mod;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
