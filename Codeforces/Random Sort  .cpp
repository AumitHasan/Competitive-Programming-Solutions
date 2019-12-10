#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define sc(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)

#define MX 100007
#define mod 7901
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

int ar[1003],ck[1003],fact[1003];

void pre()
{
    fact[1] = 1;
    for(int i=2;i<=1000;i++) fact[i] = (fact[i-1] * i) % mod;
}
int main()
{
    pre();
    //

    int t,n,tmp;
    sc(t);
    while(t--){
        mem(ck,0);

        sc(n);
        for(int i=0;i<n;i++){
            sc(tmp);
            ck[tmp]++;
        }
        ll ans = 1;

        for(int i=1;i<=1000;i++){
            if(ck[i]>0){
                ans = (ans * fact[ck[i]]) % mod;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
