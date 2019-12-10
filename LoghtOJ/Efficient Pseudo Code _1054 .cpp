#include<bits/stdc++.h>
using namespace std;

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
int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};

#define mx 67082
#define prime_mx 6684

bitset<mx>mark;
ll prime[prime_mx],m;

void seive()
{
    int in=-1;
    prime[++in] = 2;
    for(int i=3;i<=259;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=261;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
    //cout<<in<<" "<<prime[in]<<endl;
}
ll bigmod(ll n,ll pow)
{
    if(pow==0) return 1;
    else if(pow==1) return n;

    ll val=0,v=0;
    if(pow%2==1){
        return ( n * bigmod(n,pow-1) )%MOD;
    }
    else if(pow%2==0){
        val = bigmod(n,pow/2)%MOD;
        return (val*val)%MOD;
    }
}
ll fact(ll n)
{
    ll div = 1;
    for(int i=0;i<prime_mx && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            ll c = 0;
            while(n%prime[i]==0){
                n/=prime[i];
                ++c;
            }
            ll x = bigmod(prime[i],c*m + 1)-1;
            if(x<0) x = 1;
            ll y = bigmod((prime[i]-1),MOD-2);
            if(x==1) y = 1;
            div = (div * (x%MOD * y%MOD ) )%MOD;
        }
    }
    if(n>=2){
        //cout<<n<<endl;
        ll x = bigmod(n,1*m + 1)-1;
        //cout<<x<<endl;
        if(x<0) x = 1;
        ll y = bigmod(n-1,MOD-2);
        if(x==1) y = 1;
        div = (div * (x%MOD * y%MOD ) )%MOD;
    }

    return div%MOD;
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");
    seive();
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        ll num;
        scanf("%lld %lld",&num ,&m);

        ll res = fact(num);
        printf("Case %d: %lld\n",N,res);
    }
    return 0;
}
