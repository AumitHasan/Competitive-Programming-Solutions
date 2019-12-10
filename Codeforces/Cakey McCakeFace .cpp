#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 2007
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

int x,a[mx],n,m,in;
umap<int,int>mp;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int i=0;i<m;i++){
        scanf("%d",&x);
        for(int j=0;j<n;j++){
            if(x>=a[j]){
                mp[x-a[j]]++;
            }
        }
    }
    ll val=0,ans=0;
    umap<int,int>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it){
        if(it->second >ans){
            ans = it->second;
            val = it->first;
        }
        else if(it->second == ans){
            if(it->first<val) val = it->first;
        }
    }
    cout<<val<<endl;
}
