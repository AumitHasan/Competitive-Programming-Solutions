#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1007

int n,ar[MAX],dp[MAX][MAX];

int call(int i,int j)
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ret = 0,ans=0;
    ret = max(ar[i] + min(call(i+2,j),call(i+1,j-1)), ar[j] + min(call(i+1,j-1),call(i,j-2)));
    //ans = max(ret,ans);
    return dp[i][j] = ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int sum = 0;
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%d", &ar[i]);
            sum += ar[i];
        }
        mem(dp,-1);
        int res = call(0,n-1);
        cout<<res - (sum-res)<<endl;
    }
}
