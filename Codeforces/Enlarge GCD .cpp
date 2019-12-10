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


#define     mx                      300007

////

int n,in,ar[mx],prime[mx];
bool mark[mx];
map<int,int>mp;
vector<int>v;

void seive()
{
    in = -1;
    prime[++in] = 2;
    for(int i=3;i*i<mx;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=3;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
}
void fact(int val)
{
    for(int i=0;prime[i]*prime[i]<=val;i++){
        if(val%prime[i]==0){
            mp[prime[i]]++;
            while(val%prime[i] == 0) val /= prime[i];
        }
    }
    if(val) mp[val]++;
}
int main()
{
    sci(n);
    int f = 0;
    for(int i=0;i<n;i++){
        sci(ar[i]);
        if(i>0){
            if(ar[i] != ar[i-1]) f = 1;
        }
    }
    if(!f){
        pf(-1);
        return 0;
    }

    sort(ar,ar+n);
    int g = ar[0];
    for(int i=1;i<n;i++) g = __gcd(max(g,ar[i]),min(g,ar[i]));

    for(int i=0;i<n;i++) v.push_back(ar[i] / g);

    seive();
    //cout<<in;
    for(int i=0;i<v.size();i++){
        if(v[i]>1)fact(v[i]);
    }

    int res = 0;
    for(map<int,int>::iterator it=mp.begin(); it!=mp.end();++it){
        res = max(res, it->second);
    }
    cout<<n-res<<endl;
}
