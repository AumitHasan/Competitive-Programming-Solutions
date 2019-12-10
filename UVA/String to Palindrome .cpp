#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))

int dp[1001][1001];
string str;

int call(int i,int j)
{
    if(i==j || i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int P=1e9;

    if(str[i]==str[j]) P = min(P,call(i+1,j-1));
    if(str[i]!=str[j]) P = min(P,1 + call(i+1,j-1));
    P = min(P,1 + call(i+1,j));
    P = min(P,1 + call(i,j-1));

    return dp[i][j] = P;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        cin>>str;
        mem(dp,-1);
        int res = call(0,str.length()-1);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
