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

#define mx 100007


int main()
{
    ll n,m,k,c=1e9;
    cin>>n>>m>>k;
    double tmp;
    ll clas = n - (m-k);
    for(ll i=1;i<=clas;i++){
        tmp = (i/(n*1.0))*100.0;
        if(tmp >= 70.0){
            c = i; break;
        }
    }
    if(c<1e9){
        cout<<(c-k)<<endl;
    }
    else cout<<-1<<endl;

    double x = (clas/(n*1.0)) * 100.0 ;
    ll aa = x;
    cout<<aa<<endl;
}
