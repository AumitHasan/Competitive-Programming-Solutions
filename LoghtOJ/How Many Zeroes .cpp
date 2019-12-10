#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long int

ll dp[20][2][2][20],len;
vector<int>A;

ll call(int pos,int flag,int isStart,int value)
{
    //cout<<pos<<" "<<flag<<" "<<endl;
    if(pos>=len) return value;
    if(dp[pos][flag][isStart][value] != -1) return dp[pos][flag][isStart][value];

    ll ret = 0;
    int lim = 9,c;
    if(flag) lim = A[pos];

    bool check = false;

    if(isStart){
        for(int i=1;i<=lim;i++){
            if(flag && i==lim) check = true;
            ret += call(pos+1,check,0,value);
        }
        ret += call(pos+1,0,1,0);
    }
    else{
        for(int i=0;i<=lim;i++){
            if(flag && i==lim) check = true;
            c = (i==0) ? 1 : 0;
            ret += call(pos+1,check,0,value+c);
        }
    }

    return dp[pos][flag][isStart][value] = ret;
}
ll solve(ll num)
{
    if(num<0) return 0;
    if(num<10) return 1;
    A.clear();
    while(num>0){
        A.push_back(num%10);
        num/=10;
    }
    reverse(A.begin(),A.end());
    len = A.size();
    mem(dp,-1);
    return call(0,1,1,0) + 1;
}
int main()
{
    string str;
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        ll num;
        scanf("%lld",&num);
        ll res1 = solve(num-1);
        scanf("%lld",&num);
        ll res2 = solve(num);
        ll ans = res2 - res1;
        printf("Case %d: %lld\n",N,ans);
    }
    return 0;
}
