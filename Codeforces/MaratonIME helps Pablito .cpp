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
#define sqr(a) a*a

#define mx 100007

struct st{
    ll x,y,r;
}ar[1007];

void solve()
{
    ll a,b,g;
    cin>>a>>b;
    g = __gcd(a,b);
    //cout<<g<<endl;
    if(g>1 && g!=a && g!=b) cout<<"Sim"<<endl;
    else cout<<"Nao"<<endl;
}
int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i].x>>ar[i].y>>ar[i].r;

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ll dis = (ar[i].x - ar[j].x)*(ar[i].x - ar[j].x) + (ar[i].y - ar[j].y)*(ar[i].y - ar[j].y);

            dis = sqrt(dis);
            if(ar[j].r>=(2*ar[i].r + (dis-ar[i].r)) || ar[i].r>=(2*ar[j].r + (dis-ar[j].r)))
                continue;
            //cout<<dis<<endl;
            if(dis<=(ar[i].r+ar[j].r)) cout<<i<<" "<<j<<endl;
        }
    }
}
