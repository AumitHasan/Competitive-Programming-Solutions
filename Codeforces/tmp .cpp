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

int ar[mx];

int main()
{
    int n,m,tmp;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        ar[tmp]++;
    }
    int mn = 1e7;
    for(int i=1;i<=n;i++){
        mn = min(mn,ar[i]);
    }
    cout<<mn<<endl;
}
