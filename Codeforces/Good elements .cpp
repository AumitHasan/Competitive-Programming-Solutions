#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 5007
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

int n,ar[5008];
umap<int,int>mp,res;

int main()
{
    int x,c=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
        //nw[ar[i]] = max(nw[ar[i]],i);
        if(mp[ar[i]]==0) mp[ar[i]] = i;
    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            x = ar[i] + ar[j];
            if(res[x]==0) res[x] = j;
            else res[x] = min(res[x],j);
        }
    }

    bool flag;
    for(int i=n;i>1;i--){
        flag = false;
        for(int j=1;j<i;j++){

            x = ar[j] + ar[j];
            x = ar[i] - x;
            if(mp[x] && mp[x]<i){
                c++;
                break;
            }
            x = ar[i] - ar[j];
            if(res[x] && res[x]<i){
                c++;
                break;
            }
        }
    }
    cout<<c<<endl;
}
