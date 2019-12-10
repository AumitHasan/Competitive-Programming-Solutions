#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_mapa
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

int ar[mx],sum[mx],jog[mx];

int main()
{
    int n,k,tmp;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        tmp = ar[i];
        sum[i] = sum[i-1] + tmp;
    }
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp) jog[i] = jog[i-1] + ar[i];
        else jog[i] = jog[i-1];
    }
    int ans = 0;
    for(int i=1;i<=n-k+1;i++){
        int a = jog[i-1];
        int b = sum[i+k-1] - sum[i-1] ;
        int c = jog[n] - jog[i+k-1];
        ans = max(ans, a+b+c);
    }
    cout<<ans<<endl;
}
