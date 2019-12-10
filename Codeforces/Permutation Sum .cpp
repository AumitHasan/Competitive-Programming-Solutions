#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007

int ar[] = {0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};
int lim;
ll n,ans,fact[17];

//void call(int pos,int mask1,int mask2)
//{
//    if(pos>=n){
//        if(mask2==lim) ans++;
//        ans %= mod;
//        return;
//    }
//
//    for(int i=0;i<n;i++){
//        if(!(mask1 & (1<<i))){
//            int cur = (i+pos) % n;
//            if(!(mask2 & (1<<cur))){
//                call(pos+1,mask1|(1<<i),mask2|(1<<cur));
//            }
//        }
//    }
//}
int main()
{
    cin>>n;
    if(n&1){
//        fact[1] = 1;
//        for(int i=2;i<=16;i++) fact[i] = (fact[i-1] * i) % mod;
//        //
//        lim = (1<<n) - 1;
//        call(0,0,0);
//        //cout<<ans<<" "<<fact[n]<<endl;
//        ll res = (ans * fact[n]) % mod;
        cout<<ar[n]<<endl;
    }
    else cout<<0<<endl;
}
