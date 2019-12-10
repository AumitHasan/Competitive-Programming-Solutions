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
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int ans = 0,tmp,x;
        while(a>0 && b>0){
            if(a==b){
                ans++; break;
            }
            if(a>b) swap(a,b);

            tmp = b - a;
            x = tmp/a;
            if(tmp%a != 0) x++;
            ans += x;
            b -= a*x;
        }
        cout<<ans<<endl;
    }
}
