#include<bits/stdc++.h>
using namespace std;

#define mx 61
#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))

ll dp[mx][mx];
char str[100];

ll call(int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    if(i>j) return 0;
    if(i==j){
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];

    ll P=0;

    if(str[i]==str[j]){
        P = 1 +  call(i+1,j) + call(i,j-1);
    }
    else P = call(i+1,j) + call(i,j-1) - call(i+1,j-1);

    return dp[i][j] = P;
}
int main()
{
    int T,N=0;
    scanf("%d", &T);
    while(++N<=T){
        scanf("%s",str);
        mem(dp,-1);
        ll res = call(0,strlen(str)-1);
        printf("Case %d: %lld\n", N, res);
    }
    return 0;
}
