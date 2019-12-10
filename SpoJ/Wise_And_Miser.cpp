
#include<bits/stdc++.h>
using namespace std;

#define st(a) memset(a,-1,sizeof(a))

int row,col,grid[101][101],dp[101][101];


int stone(int i,int j)
{
    if(i>=row) return 0;
    if(j>=col || j<0) return 10000000;
    if(dp[i][j] != -1) return dp[i][j];

    int s1=INFINITY,s2=INFINITY,s3=INFINITY;

     if(i>=0 && i<=row && j>=0 && j<=col) s1 = stone(i+1,j-1)+grid[i][j];
     if(i>=0 && i<=row && j>=0 && j<=col) s2 = stone(i+1,j)+grid[i][j];
     if(i>=0 && i<=row && j>=0 && j<=col) s3 = stone(i+1,j+1)+grid[i][j];
    //dp[i][j]= stone(i+1,j-1)+grid[i][j];
    //dp[i][j]= stone(i+1,j)+grid[i][j];
    //dp[i][j]= stone(i+1,j+1)+grid[i][j];

    //cout<<s1<<" "<<s2<<" "<<s3<<endl;
    //if(s1==0) s1=INFINITY;
    //if(s2==0) s2=INFINITY;
    //if(s3==0) s3=INFINITY;

    dp[i][j] = min(min(s1,s2),s3);
    //dp[i][j] = max(max(s1,s2),s3);

return dp[i][j];
}

int main()
{
        scanf("%d%d",&row,&col);
        //int grid[row][col];
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++) scanf("%d",&grid[i][j]);

        int sum = INFINITY;
        //int sum=0;
         //st(dp);
        for(int i=0;i<col;i++)
        {
            st(dp);
            //cout<<stone(0,i)<<endl;
            sum = min(sum,stone(0,i));
            /*for(int i=0;i<row;i++){
                for(int j=0;j<col;j++) printf("%d ",dp[i][j]);
                cout<<endl;
                //cout<<"s: "<<s1<<" "<<s2<<" "<<s3<<" s"<<endl;
            }
            cout<<endl<<"_______________"<<endl;*/
        }
        cout<<sum<<endl;



return 0;
}
