#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)

int dp[10003][103][2],ar[10003],n,k;

int call(int i,int val,int sign)
{
    //cout<<i<<" "<<val<<" "<<sign<<endl;
    if(i>=n){
        if(val%k==0){
            //cout<<"v: "<<val<<endl;
            return 1;
        }
        return 0;
    }
    if(dp[i][val][sign]!=-1) return dp[i][val][sign];

    bool flag=false;
    int x,y,P=0;
    //cout<<i<<" "<<ar[i]<<" "<<val<<" "<<sign<<endl;
    if(sign==0){
        x = val + ar[i];
        if(x<0) flag = true;
        else flag = true;
        P |= call(i+1,abs(x)%k,flag);

        x = val - ar[i];
        if(x<0) flag = true;
        else flag = false;

        P |= call(i+1,abs(x)%k,flag);
    }
    else{
        x = -val + ar[i];
        if(x<0) flag = true;

        P |= call(i+1,abs(x)%k,flag);

        x = -val - ar[i];
        if(x<0) flag = true;
        else flag = false;

        P |= call(i+1,abs(x)%k,flag);
    }
    return dp[i][val][sign] = P;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);

        bool flag = false;
        if(ar[0]<0) flag = true;
        //cout<<abs(ar[0])<<endl;
        mem(dp,-1);
        //int res = call(1,abs(ar[0]),flag);
        int res = call(0,0,0);
        if(res) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}
