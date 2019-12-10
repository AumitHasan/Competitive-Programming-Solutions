#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)

#define     mx                      100007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////




ll seq(ll n)
{
    if(n<=0) return 0;
    return (n*(n+1))/2;
}
int main()
{
    ll n,m,x,d,sum=0;

    scll(n,m);
    ll L,R,pre = n-1;

    for(int i=0;i<m;i++){
        scll(x,d);
        if(x>=0) sum += x*n;
        else sum += x*n;
        //cout<<sum<<endl;
        if(d<0){
            L = pre/2;
            R = pre/2 + (pre%2);
            sum += d * seq(L);
            sum += d * seq(R);
        }
        else sum += d * seq(pre);
        //cout<<sum<<endl<<endl;
    }
    //cout<<sum<<endl;
    if(sum<0){
        printf("-");
        sum = (sum*-1);
        //cout<<sum<<endl;
    }
    double ans = (sum*1.0) / (n*1.0);
    //cout<<ans<<endl;
    printf("%.10f",ans);

}
