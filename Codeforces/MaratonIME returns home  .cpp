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
    int n,m;
    cin>>n>>m;
    string str[n];
    for(int i=0;i<n;i++) cin>>str[i];

    bool flag = true;
    int tk=0,ans=0;

    for(int i=0;i<n;i++){
        flag = 1 - flag;
        if(!flag){
            for(int j=0;j<m;j++){
                if(str[i][j]=='.') tk++;
                ans = max(tk,ans);
                if(str[i][j]=='L') tk=0;
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                if(str[i][j]=='.') tk++;
                ans = max(tk,ans);
                if(str[i][j]=='L') tk=0;
            }
        }
    }
    cout<<max(tk,ans)<<endl;
}
