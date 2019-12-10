#include<bits/stdc++.h>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
#define set(a) memset(a,-1,sizeof(a))

int row,col,g[102][102],dp[102][102];

int stone(int i,int j)
{
    if(i<0 ||i==row||j<0||j==col) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int a=0,b=0,c=0;
    a=stone(i+1,j-1)+g[i][j];
    b=stone(i+1,j)+g[i][j];
    c=stone(i+1,j+1)+g[i][j];

    dp[i][j]=max(max(a,b),c);
return dp[i][j];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&row,&col);
        clr(g);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++) scanf("%d",&g[i][j]);
        int sum=0;
        for(int i=0;i<col;i++)
        {
            set(dp);
            int v = stone(i,0);
            sum = max(sum,v);
        }

        printf("%d\n",sum);

    }

return 0;
}
