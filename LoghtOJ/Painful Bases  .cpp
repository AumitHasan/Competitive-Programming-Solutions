#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))

int num[19],sz,base,k,idx,lim;
long long int dp[22][65540];


long long call(int val,int mask)
{
    if(mask==(1<<sz)-1){
        if(val%k==0) return 1;
        return 0;
    }
    if(dp[val][mask]!=-1) return dp[val][mask];

    long long int p=0;

    for(int i=0;i<=idx;i++){
        if(!(mask & (1<<i))){
            p += call( (val*base+num[i])%k , (mask | (1<<i)) );
        }
    }

    return dp[val][mask] = p;
}
int main()
{
    int N=0,T;
    scanf("%d",&T);
    while(++N<=T){
        mem(dp,-1);
        string s;
        idx=-1;
        int in;
        scanf("%d %d",&base ,&k);
        cin>>s;
        sz=s.length();

        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9') num[++idx] = s[i]-'0';
            else num[++idx] = s[i]-'A'+10;
        }

        long long int res = call(0,0);
        printf("Case %d: %lld\n",N,res);
    }
    return 0;
}
