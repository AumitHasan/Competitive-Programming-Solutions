#include<bits/stdc++.h>
using namespace std;

#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define sf scanf
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))

int row,col,dp[5003][5003];
bool ar[5003][5003];

string str;
stringstream ss;

int call(int i,int j)
{
    if(ar[i][j] || i>=row || j>=col) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i==row-1 && j==col-1) return 1;

    int ans=0,ret = 0;

    ret += call(i,j+1);
    ret += call(i+1,j);

    return dp[i][j] = ret;
}
int main()
{
    //READ("in.txt");
    int T,N=0,x,y,tmp;
    sf("%d ",&T);

    while(++N<=T){
        if(N>1) printf("\n");
        mem(ar,0);
        sf("%d %d",&row,&col);
        cin.ignore();

        for(int k=0;k<row;k++){
            getline(cin,str);
            ss.clear();
            ss.str(str);
            bool flag = false;
            while(ss >> tmp){
                if(flag)  ar[k][tmp-1] = 1;
                else flag = true;
            }


        }
        mem(dp,-1);
        int ans = call(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
