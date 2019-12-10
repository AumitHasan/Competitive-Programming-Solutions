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

int ar[mx],n,uni_ar[mx],fen[mx],sz,cnt[mx],L[mx],R[mx];

int query(int idx)
{
    int sum = 0;
    while(idx>0){
        sum += fen[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void add(int idx,int val) // update
{
    while(idx<=n){
        fen[idx] -= val;
        idx += idx & (-idx);
    }
}
int main()
{
    sci(n);
    for(int i=0;i<n;i++) sci(ar[i]), uni_ar[sz++] = ar[i];

    sort(uni_ar,uni_ar+sz); //for numbering next 3 lines
    sz = unique(uni_ar,uni_ar+sz) - uni_ar;
    for(int i=0;i<n;i++) ar[i] = lower_bound(uni_ar,uni_ar+sz,ar[i]) - uni_ar;

    for(int i=0;i<n;i++) L[i] = ++cnt[ar[i]];

    mem(cnt,0);
    for(int i=n-1;i>=0;i--){
        cnt[ar[i]]++;
        R[i] = cnt[ar[i]];
        add(cnt[ar[i]], -1);
    }
    ll ans = 0;
    int val;
    for(int i=0;i<n-1;i++){
        add(R[i],1);
        if(L[i]<=1) continue;
        val = query(L[i]-1);
        ans += (ll) val;
        //cout<<L[i]<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
}
