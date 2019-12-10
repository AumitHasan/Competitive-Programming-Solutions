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

#define mx 1007

int n,tk,ar[mx];

int main()
{
    int test=0;
    while(scanf("%d",&n)){
        if(!n) break;
        //
        mem(ar,0);
        int ttl=0,ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&tk);
                ttl += tk;
                ar[i] += tk; ar[j] -= tk;
            }
        }
        //
        for(int i=1;i<=n;i++){
            if(ar[i]<0) ans += abs(ar[i]);
        }
        printf("%d. %d %d\n",++test,ttl,ans);
    }
    return 0;
}
