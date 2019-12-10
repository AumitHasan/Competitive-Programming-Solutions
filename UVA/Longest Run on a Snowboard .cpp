#include<bits/stdc++.h>
using namespace std;


int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 107

int ar[MAX][MAX],dp[MAX][MAX],n,row,col;

int call(int i,int j,int val)
{
    //cout<<i<<" "<<j<<endl;
    if(i<0 || i>=row || j<0 || j>=col) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret = 0;
    for(int k=0;k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x>=0 && x<row && y>=0 && y<col && val>ar[x][y]){
            ret = max(ret, 1 + call(x,y,ar[x][y]));
        }
    }
    //cout<<ret<<endl;
    return dp[i][j] = ret;
}
int main()
{
    string name;
    int T;
    scanf("%d",&T);
    while(T--){
        cin>>name;
        scanf("%d %d",&row,&col);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++) scanf("%d",&ar[i][j]);
        }
        mem(dp,-1);
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans = max(ans, call(i,j,ar[i][j]));
            }
        }
        cout<<name<<": "<<ans+1<<endl;
    }
    return 0;
}
