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

string str[17];
int n,lim,life[17],dp[1<<16][2];

inline int st(int f,int p)
{
    int x = f/p;
    if(f%p != 0) x++;
    return x;
}
int call(int mask,int ck)
{
    if(mask == lim) return 0;
    if(dp[mask][ck] != -1) return dp[mask][ck];

    int ret = 1e9;



        for(int j=0;j<n;j++){
            //
            if(!(mask & 1<<j)){
                int pw = 0;
                for(int i=0;i<n;i++){
                    if((mask & 1<<i)){
                        //cout<<i<<endl;
                        pw = max(pw, str[i][j] - '0');
                    }
                }
                if(pw==0) pw = 1;
                int tmp = mask;
                tmp = tmp | 1<<j;
                //cout<<j<<" "<<pw<<" "<<st(life[j],pw)<<" "<<mask<<" "<<tmp<<endl;
                ret = min(ret, st(life[j],pw) + call(tmp, 1));
            }
        }


    return dp[mask][ck] = ret;
}
int main()
{
    int T,N=0;
    scanf("%d", &T);
    while(++N<=T){
        scanf("%d", &n);
        lim = (1<<n) - 1;
        for(int i=0;i<n;i++) scanf("%d", &life[i]);
        for(int i=0;i<n;i++) cin>>str[i];
        mem(dp,-1);
        int res = call(0,0);
        printf("Case %d: %d\n", N, res);
    }
    return 0;
}
