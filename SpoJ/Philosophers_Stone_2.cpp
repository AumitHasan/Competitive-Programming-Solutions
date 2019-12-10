#include<bits/stdc++.h>
using namespace std;

#define st(a) memset(a,-1,sizeof(a))

int row,col,grid[101][101],dp[101][101];

int stone(int i,int j)
{
    if(i<0 || i>=row || j<0 || j>=col) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int s1 = stone(i+1,j-1)+grid[i][j];
    int s2 = stone(i+1,j)+grid[i][j];
    int s3 = stone(i+1,j+1)+grid[i][j];

    dp[i][j] = max(max(s1,s2),s3);
    //dp[i][j] = min(min(s1,s2),s3);

return dp[i][j];
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&row,&col);
        //int grid[row][col];
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++) scanf("%d",&grid[i][j]);

        int sum = 0;
        for(int i=0;i<col;i++)
        {
            st(dp);
            sum = max(sum,stone(0,i));

            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++) printf("%d ",dp[i][j]);
                cout<<endl;
            }
            cout<<endl<<"_______________"<<endl;
        }
        cout<<sum<<endl;
    }

return 0;
}

