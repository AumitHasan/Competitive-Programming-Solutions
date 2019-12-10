#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define umap unordered_map

int n,ar[55],sum,A,B,mx = 1e9;

umap<int,umap<int,umap<int,umap<int,int> > > >dp;

int call(int i,int a,int b,int val)
{
    if(i==n){
        int x = sum - val;
        int y = val;
        if(y>=x && y-x<mx) A = x; B = y; mx = y-x;
        return 0;
    }
    if(dp[i][a][b][val] != 0) return dp[i][a][b][val];

    int ret = 0;

    if(a){
        ret = call(i+1,1,0,val+ar[i]);
        ret = call(i+1,0,1,val);
    }
    if(b){
        ret = call(i+1,0,1,val);
        ret = call(i+1,1,0,val+ar[i]);
    }
    return dp[i][a][b][val] = ret;
}
int main()
{
    cin>>n;
    sum = 0;
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]); sum += ar[i];
    }
    //memset(dp,-1,sizeof(dp));
    int res = call(0,0,1,0);

    if(A+B != sum) B += sum - abs(A+B);
    cout<<A<<" "<<B<<endl;

}
