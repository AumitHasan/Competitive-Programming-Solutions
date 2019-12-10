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
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      30076

////

int n,ar[mx][4],dp[mx][4][2];


int call(int pos,int last,int one,int val)
{
    cout<<pos<<" "<<last<<" "<<one<<" "<<val<<endl;

    if(pos>=n){
        pf("x");
        if(one) return 0;
        return -2e9;
    }
    if(dp[pos][last][one] != -1) return dp[pos][last][one];

    int res = 0;

    for(int i=1;i<=3;i++){
        if((pos==0 || pos==n-1) && i==3) continue;

        if(i==3){
            if(one) res = max(res, ar[pos][i] + call(pos+1,i,0,val+ar[pos][i]));
        }
        else if(i==2){
            res = max(res, ar[pos][i] + call(pos+1,i,one,val+ar[pos][i]) );
        }
        else if(i==1 && last != 1){
            //bool check = (i==1) ? 1 : 0;
            res = max(res, ar[pos][i] + call(pos+1,i,1,val+ar[pos][i]) );
            //res = max(res, ar[pos][i] + call(pos+1,i,(i==1) ? 1 : 0) );
        }
    }
    return dp[pos][last][one] = res;
}
int main()
{
    sci(n);
    for(int i=0;i<n;i++) sci(ar[i][1]);
    for(int i=0;i<n;i++) sci(ar[i][2]);
    for(int i=0;i<n;i++) sci(ar[i][3]);

    mem(dp,-1);
    pf(call(0,0,0,0));

    return 0;
}
