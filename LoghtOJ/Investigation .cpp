#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100007

int len,mod,x,y,dp[10][2][2][90][90];
vector<int>A;

int call(int pos,int isSmall,int isStart,int sum,int mul)
{
    if(pos>=len){
        if(!sum && !mul && !isStart) return 1;
        return 0;
    }
    if(dp[pos][isSmall][isStart][sum][mul] != -1) return dp[pos][isSmall][isStart][sum][mul];

    int lim = 9,ret = 0;
    if(isSmall) lim = A[pos];
    bool check = false;

    if(isStart){
        for(int i=1;i<=lim;i++){
            if(isSmall && i==lim) check = true;
            x = (mul*10) + i;
            ret += call(pos+1,check,0,(sum+i)%mod,x%mod);
        }
        ret += call(pos+1,0,1,0,0);
    }
    else{
        for(int i=0;i<=lim;i++){
            if(isSmall && i==lim) check = true;
            x = (mul*10) + i;
            ret += call(pos+1,check,0,(sum+i)%mod,x%mod);
        }
    }
    return dp[pos][isSmall][isStart][sum][mul] = ret;
}
int solve(int a,int b)
{
    if(mod>90) return 0;
    a--;
    int s,e;
    if(a>0){
        A.clear();
        while(a>0){
            A.push_back(a%10);
            a/=10;
        }
        reverse(A.begin(),A.end());
        len = A.size();
        mem(dp,-1);
        s = call(0,1,1,0,0);
    }
    else s = 0;
    A.clear();
    while(b>0){
        A.push_back(b%10);
        b/=10;
    }
    reverse(A.begin(),A.end());
    len = A.size();
    mem(dp,-1);
    e = call(0,1,1,0,0);

    return e - s;
}
int main()
{
    int T,N=0,a,b;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d %d %d",&a,&b,&mod);
        int ans = solve(a,b);
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
