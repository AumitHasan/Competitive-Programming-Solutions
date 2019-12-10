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


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      300007

////

ll ans,n,a[mx],b[mx],la[mx],ra[mx],lb[mx],rb[mx],sumA[mx],sumB[mx];


ll up(int col,int s)
{
    if(col==n) return -0;

    ll val = la[n] - la[col] - (sumA[n]-sumA[col])*col;
    val += (sumA[n]-sumA[col]) * (s+1);
    //cout<<val<<endl;

    if(s<0) s = n;
    else s += n-s + 1;

    val += rb[col+1] + (sumB[n]-sumB[col])*s;
    //cout<<val<<endl;
    return val;
}
ll down(int col,int s)
{
    if(col==n) return 0;

    ll val = lb[n] - lb[col] - (sumB[n]-sumB[col])*col;
    val += (sumB[n]-sumB[col]) * (s+1);
    //cout<<"v: "<<val<<endl;
    s += n-s + 1;
    //cout<<"s: "<<s<<endl;
    val += ra[col+1] + (sumA[n]-sumA[col])*s;
    //cout<<ra[col+1]<<" "<<(sumA[n]-sumA[col])*s<<endl;
    //cout<<val<<endl;
    return val;
}
int main()
{
    scl(n);
    int cur = 0;
    for(int i=1;i<=n;i++){
        scl(a[i]);
        sumA[i] = a[i] + sumA[i-1];
        la[i] = la[i-1] + a[i]*cur;
        cur++;
    }
    cur = -1;
    for(int i=n;i>0;i--) ra[i] = ra[i+1] + a[i]*++cur;

    cur = 0;
    for(int i=1;i<=n;i++){
        scl(b[i]);
        sumB[i] = b[i] + sumB[i-1];
        lb[i] = lb[i-1] + b[i]*cur;
        cur++;
    }
    cur = -1;
    for(int i=n;i>0;i--) rb[i] = rb[i+1] + b[i]*++cur;


    int s = -1;
    ll tmp,val = 0;

    ans = up(0,-1);
    //cout<<ans<<endl;

    for(int i=1;i<=n;i++){
        if(i&1){ // down
            val += a[i]*++s + b[i]*++s;
            ans = max(ans, val + down(i,s));
        }
        else{ // up
            val += b[i]*++s + a[i]*++s;
            ans = max(ans, val + up(i,s));
        }
       // cout<<val<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
