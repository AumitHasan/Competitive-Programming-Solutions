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
    int ar[107],n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];
    sort(ar,ar+n);
    for(int i=0;i<n;i++){
        cout<<ar[i];
        if(i==n-1) cout<<endl;
        else cout<<" ";
    }
    return 0;
}

