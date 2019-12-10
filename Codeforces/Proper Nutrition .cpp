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

ll a,b,n;

int main()
{
    ll x,y;

    cin>>n>>a>>b;


    for(ll i=0;i<=1e7;i++){
        x = i;
        y = n - a*x;
        if(y>=0){
            y = (y==0) ? 0 : (y/b);
            if((x*a + y*b) == n){
                cout<<"YES"<<endl;
                cout<<x<<" "<<y<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}
