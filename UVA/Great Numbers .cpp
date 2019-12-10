#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000007
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

int n,f[7],dp[41][61][2][2][2][2][2];

int call(int pos,int num,int two,int three,int four,int five,int six)
{
    if(pos>=n){

        bool flag = false;
        if(two && num%2 != 0) flag = 1;
        if(three && (num%3 != 0)) flag = 1;
        if(four && num%4 != 0) flag = 1;
        if(five && num%5 != 0) flag = 1;
        if(six && num%6 != 0) flag = 1;

        if(flag) return 0;
        //cout<<num<<" "<<two<<" "<<three<<" "<<four<<" "<<five<<" "<<six<<endl;
        return 1;
    }
    if(dp[pos][num][two][three][four][five][six] != -1) return dp[pos][num][two][three][four][five][six];

    int ans=0,tnum;

    for(int i=1;i<=6;i++){
        f[2] = two; f[3] = three; f[4] = four; f[5] = five; f[6] = six;
        f[i] = 1;
        tnum = (num*10) + i;
        ans = (ans%mod) + call(pos+1,tnum%60,f[2],f[3],f[4],f[5],f[6]) % mod;
    }
    return dp[pos][num][two][three][four][five][six] = ans % mod;
}
void solve()
{
    scanf("%d",&n);
    mem(dp,-1);
    int res = call(0,0,0,0,0,0,0) % mod;
    printf("%d\n",res);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
