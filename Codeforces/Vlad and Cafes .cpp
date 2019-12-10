#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 200007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

map<int,int>mp;
int ar[mx];

int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    //
    for(int i=n;i>0;i--){
        if(mp[ar[i]]==0){
            mp[ar[i]] = i;
        }
    }
    map<int,int>:: iterator it;
    int ans=0,ix = 1e9;
    for(it = mp.begin(); it != mp.end(); ++it){
        if(it->second < ix){
            ix = it->second;
            ans = it->first;
        }
    }
    cout<<ans<<endl;
}
