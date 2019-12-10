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

#define mx 150007

bool f[150000];
int ar[503][503],n,m,prime[mx];

void seive()
{
    f[1] = 1;
    for(int i=4;i<mx;i+=2) f[i] = 1;

    for(int i=3;i<=400;i+=2){
        if(!f[i]){
            for(int j=i*i;j<mx;j+=2*i) f[j] = 1;
        }
    }
    int last;
    for(int i=100003;i>0;i--){
        if(!f[i]) last = i;
        prime[i] = last - i;
    }
    //for(int i=1;i<=20;i++) cout<<prime[i]<<" ";
}
int main()
{
    seive();

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>ar[i][j];
    }
    ll ans = 1e18;

    for(int i=1;i<=n;i++){
        ll tmp = 0;
        for(int j=1;j<=m;j++) tmp += prime[ar[i][j]];
        ans = min(ans,tmp);
    }

    for(int i=1;i<=m;i++){
        ll tmp = 0;
        for(int j=1;j<=n;j++) tmp += prime[ar[j][i]];
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;
}
