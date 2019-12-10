#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 25

int m,c,num,k,dp[MAX][107];
vector<int>v[MAX];

int call(int i,int val)
{
    //cout<<val<<endl;
    if(val>m) return -1e7;
    if(i==c) return val;
    if(dp[i][val] != -1) return dp[i][val];

    int ret = -1e8;
    for(int j=0;j<v[i].size();j++){
        ret = max(ret, call(i+1,val + v[i][j]));
    }
    return dp[i][val] = ret;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        mem(v,0);
        scanf("%d %d", &m, &c);
        for(int i=0;i<c;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&num);
                v[i].push_back(num);
            }
        }
        mem(dp,-1);
        int ans = call(0,0);

        if(ans<=0) printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}
