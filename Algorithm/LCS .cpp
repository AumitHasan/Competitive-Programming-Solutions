#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a));
#define M 1001

int dp[M][M],lenA,lenB;
char A[M],B[M];
string ans,ansALL;

int LCS(int i,int j) // calculate length of LCS
{
    if(A[i]=='\0' || B[j]=='\0') return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int len = 0;
    if(A[i]==B[j])
        len = 1+LCS(i+1,j+1);
    else
        len = max(LCS(i+1,j),LCS(i,j+1));

    return dp[i][j] = len;
}
void printLCS(int i,int j) // print longest common string
{
    if(A[i]=='\0' || B[j]=='\0'){
        cout<<ans<<endl;
        return ;
    }
    if(A[i]==B[j]){
        ans += A[i];
        printLCS(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])
            printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}
void printALL(int i,int j)
{
    if(A[i]=='\0' || B[j]=='\0'){
        cout<<ansALL<<endl;
        return ;
    }
    if(A[i]==B[j]){
        ansALL += A[i];
        printALL(i+1,j+1);
        ansALL.erase(ansALL.end()-1);
    }
    else{
        if(dp[i][j+1]>dp[i+1][j])
            printALL(i,j+1);
        else if(dp[i+1][j]>dp[i][j+1])
            printALL(i+1,j);
        else{
            printALL(i,j+1);
            printALL(i+1,j);
        }
    }
}
int main()
{
    mem(dp,-1);

    scanf("%s %s",A,B);
    lenA = strlen(A);
    lenB = strlen(B);

    cout<<LCS(0,0)<<endl;
    printLCS(0,0); // print longest common string
    //cout<<ans<<endl;
    printALL(0,0); // print all LCS

    return 0;
}
