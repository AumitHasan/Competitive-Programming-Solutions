#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

int ck[45];
ll n,N,in;
ll dp[63][2][2][2];
string str;

ll call(int pos,int flag,int isStart,int last)
{
    if(pos>N) return 1;
    if(dp[pos][flag][isStart][last] != -1) return dp[pos][flag][isStart][last];

    ll ans = 0;
    int lim = (flag) ? 1 : ck[pos];
    int f = true;

    if(!isStart){
        int tmp = (pos==0) ? 0 : 1;
        ans += call(pos+1,tmp,1,1);
        ans += call(pos+1,1,0,0);
    }
    else{
        for(int i=0;i<=lim;i++){
            if(!flag && i==lim) f = false;
            if(i){
                if(!last) ans += call(pos+1,f,1,i);
            }
            else ans += call(pos+1,f,1,i);
        }
    }

    return dp[pos][flag][isStart][last] = ans;
}
void cnv(ll num)
{
    mem(ck,0);
    in = -1;
    while(num>0){
        ck[++in] = num%2; num/=2;
    }
    N=in;
    //
    int lo=0,hi=in;
    while(lo<hi) swap(ck[lo++],ck[hi--]);
}
ll solve()
{
    ll ans,mid,lo = 1,hi = 3e13;
    while(lo<=hi){
        mid = (lo + hi) / 2;
        cnv(mid);
        mem(dp,-1);
        ans = call(0,0,0,0) - 1;

        if(ans>n) hi = mid - 1;
        else if(ans<n) lo = mid + 1;
        else return mid;
    }
}
void get(ll num)
{
    cnv(num);
    str += "1";
    bool flag = false;
    for(int i=1;i<=in;i++){
        if(flag){
            if(str[i-1]=='0') str += "1";
            else str += "0";
        }
        else{
            if(ck[i] == 1){
                if(str[i-1] == '1'){ str += "0"; flag=1;}
                else str += "1";
            }
            else str += "0";
        }
    }
}
int main()
{
    int T,t=0;
    scanf("%d",&T);
    while(++t<=T){
        scanf("%lld",&n);
        ll ans = solve();
        //cout<<ans<<endl;
        printf("Case %d: ",t);
        str="";
        get(ans);
        printf("%s\n",str.c_str());
    }
    return 0;
}
