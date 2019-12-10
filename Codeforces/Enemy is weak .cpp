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


#define     mx                      1000007

////

int n,ar[mx],tree[mx*3],tmp[mx];
llu ncr[mx];
map<int,int>mp;

int query(int node,int i,int j,int s,int e)
{
    int mid = (i + j) / 2;
    int left = 2 * node;
    int right = left + 1;

    if(i>e || j<s) return 0;
    if(i>=s && j<=e) return tree[node];

    int a = query(left,i,mid,s,e);
    int b = query(right,mid+1,j,s,e);

    return a + b;
}
void update(int node,int i,int j,int idx)
{
    int mid = (i + j) / 2;
    int left = 2 * node;
    int right = left + 1;

    if(i>idx || j<idx) return;
    if(i>=idx && j<=idx){
        tree[node] = 1;
        return;
    }

    update(left,i,mid,idx);
    update(right,mid+1,j,idx);

    tree[node] = tree[left] + tree[right];
}
void solve()
{
    ncr[2] = 1;
    ncr[3] = 3;
    for(llu i=4;i<=1000000;i++){
        ncr[i] = (i * (i-1)) / 2;
    }
    return;
    for(int i=1;i<=10;i++) cout<<ncr[i]<<" ";
}
int main()
{
    solve();
    sci(n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        sci(ar[i]);
        tmp[i] = ar[i];
    }
    sort(tmp,tmp+n);

    int idx,cnt,c = 0;
    for(int i=0;i<n;i++) mp[tmp[i]] = ++c;

    for(int i=n-1;i>=0;i--){
        idx = mp[ar[i]];
        cnt = query(1,1,n,1,idx-1);
        //cout<<cnt<<endl;
        ans += ncr[cnt];
        update(1,1,n,idx);
    }
    cout<<ans<<endl;
}
