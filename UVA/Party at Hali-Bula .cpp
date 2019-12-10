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

#define mx 100007

int n,flag,dp[205][2],check[205][2];
umap<string,int>mp;
string emp,bos;
vector<int>edge[205];

int call(int i,int flag,int par)
{
    if(dp[i][flag] != -1) return dp[i][flag];

    int yes=0,no=0;
    if(!flag) yes = 1;

    for(auto child : edge[i]){

        if(flag) no += call(child,0,i);
        else{
            yes += call(child,1,i);
            no += call(child,0,i);
        }
    }
    //
    if(yes > no){
        for(auto v : edge[i]){
            check[i][flag] |= check[v][1];
        }
    }
    else if(yes < no){
        for(auto v : edge[i]){
            check[i][flag] |= check[v][0];
        }
    }
    else check[i][flag] = 1;
    //cout<<i<<" "<<flag<<" "<<yes<<" "<<no<<endl;
    return dp[i][flag] = max(yes,no);
}
int main()
{
    IO;

    while(cin>>n && n){
        mem(edge,0); mem(dp,-1); mem(check,0);
        mp.clear();
        //
        cin>>bos;
        mp[bos] = 1;
        int u,v,in=1;
        for(int i=1;i<n;i++){
            cin>>emp>>bos;
            if(!mp[emp]) mp[emp] = ++in;
            if(!mp[bos]) mp[bos] = ++in;
            edge[mp[bos]].push_back(mp[emp]);
        }

        int res = call(1,0,0);
        cout<<res<<" ";
        if(!check[1][0]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
