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
#define mx 10000001
#define prime_mx 664579

bitset<mx>mark;
int prime[664579];

void seive()
{
    int in=-1;
    prime[++in] = 2;
    for(int i=3;i<=3163;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=3165;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
    //cout<<in<<" "<<prime[in]<<endl;
}
ll fact(ll n)
{
    ll div = 1;
    for(int i=0;i<prime_mx && prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            int c = 1;
            while(n%prime[i]==0){
                n/=prime[i];
                ++c;
            }
            if(prime[i]>2) div *= c;
            //cout<<c<<" "<<div<<endl;
        }
    }
    if(n>2) div *= 2;
    //div--;
    if(div>1) div--;
    else div = 0;
    return div;
}
int main()
{
    seive();
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        ll n;
        scanf("%lld",&n);
        ll res = fact(n);
        printf("Case %d: %lld\n",N,res);
    }
    return 0;
}

