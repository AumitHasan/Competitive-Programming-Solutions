#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))

int n,cnt,len;
ll dp[31][2][2][31];
vector<int>A;

ll call(int pos,int isSmall,int last,int value)
{
    if(pos>=len) return value;
    if(dp[pos][isSmall][last][value] != -1) return dp[pos][isSmall][last][value];

    ll ret = 0;
    int lim = 1;
    if(isSmall) lim = A[pos];
    bool check = false;

    for(int i=0;i<=lim;i++){
        if(isSmall && lim==i) check = true;
        cnt = (last==1 && i==1) ? 1 : 0;
        ret += call(pos+1,check,i,value+cnt);
    }
    return dp[pos][isSmall][last][value] = ret;
}
ll solve(int num)
{
    A.clear();
    while(num>0){
        A.push_back(num%2);
        num/=2;
    }
    reverse(A.begin(),A.end());
    len = A.size();
    mem(dp,-1);
    return call(0,1,0,0);
}
int main()
{
    int T,N=0;
    scanf("%d", &T);
    while(++N<=T){
        scanf("%d",&n);
        ll ans = solve(n);
        printf("Case %d: %lld\n",N,ans);
    }
    return 0;
}
