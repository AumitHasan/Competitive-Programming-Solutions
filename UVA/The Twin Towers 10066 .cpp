#include<bits/stdc++.h>
using namespace std;
#define M 101
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int lenA,lenB,dp[M][M],A[M],B[M];

int LCS(int i,int j)
{
    if(i==lenA || j==lenB) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int len = 0;
    if(A[i]==B[j])
        len = LCS(i+1,j+1)+1;
    else
        len = max(LCS(i,j+1),LCS(i+1,j));

    return dp[i][j] = len;
}
int main()
{

    int N=0;
    while(1){
        scanf("%d %d",&lenA,&lenB);
        if(lenA==0 && lenB==0) break;
        mem(dp,-1);
        for(int i=0;i<lenA;i++) scanf("%d",&A[i]);
        for(int i=0;i<lenB;i++) scanf("%d",&B[i]);
        printf("Twin Towers #%d\n",++N);
        printf("Number of Tiles : %d\n\n",LCS(0,0));
    }
    return 0;
}
