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
    int n;
    cin>>n;
    int ar[n+3];
    for(int i=1;i<=n;i++) cin>>ar[i];
    int pos = 0,ans= n-1 + n;

    for(int i=1;i<=n;i++){
        if(pos<=ar[i]){
            ans += ar[i] - pos;
            pos = ar[i];
        }
        else{
            ans += pos - ar[i];
            pos = ar[i];
        }
    }
    cout<<ans<<endl;
}
