#include<bits/stdc++.h>
using namespace std;

int val[4][4] = { {0,0,0,0} ,{0,2,1,3} ,{0,1,2,2} ,{0,3,2,1} };
int ar[109],len,dp[109][109];
char ch[109];

int solve(int start,int endd)
{
    if(start == endd) return ar[start];
    if(start>endd) return 0;
    if(dp[start][endd] != -1) return dp[start][endd];

    int mid,mx = 0;
    for(mid=start;mid<endd;mid++){

        int x = solve(start,mid);
        int y = solve(mid+1,endd);
        //cout<<x<< " "<<y<<endl;
        int ans = val[x][y];
        if(ans>mx) mx = ans;
    }
    dp[start][endd] = mx;

    return dp[start][endd];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){

        memset(dp,-1,sizeof(dp));
        //memset(ar,0,sizeof(ar));
        scanf("%s",ch);
        len = strlen(ch);

        for(int i=0;i<len;i++) ar[i+1] = ch[i]-87;
        //for(int i=1;i<=len;i++) cout<<ar[i]<<" ";
        //cout<<endl;
        int res = solve(1,len);
        printf("%c\n",res+87);
    }
    return 0;
}
