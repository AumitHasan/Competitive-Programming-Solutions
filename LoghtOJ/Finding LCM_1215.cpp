#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 4000005
#define pdx 300005

map<ll,ll>mp,res,two;
bitset<mx>mark;
int prime[pdx],in=-1;

void seive()
{
    prime[++in] = 2;
    for(int i=3;i<=2000;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=2001;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
    cout<<in<<" "<<prime[in];
}
void fact(ll L)
{
    if(L==1) return;
    int x;
    for(int i=0;i<pdx && prime[i]*prime[i]<=L;i++){
        if(L%prime[i]==0){
            x = 0;
            while(L%prime[i]==0){
                L/=prime[i];
                ++x;
            }
            //if(mp[prime[i]]<x)
            mp[prime[i]] = x;
            //res[prime[i]] = x;
        }
    }
    if(L>2){
        if(mp[L]<1) mp[L] = 1;
    }

}
bool check(ll L)
{
    if(L==1) true;
    int x;
    for(int i=0;i<pdx && prime[i]*prime[i]<=L;i++){
        if(L%prime[i]==0){
            x = 0;
            while(L%prime[i]==0){
                L/=prime[i];
                ++x;
            }
            /*if(mp[prime[i]]<x) return false;
            else{
                if(res[prime[i]]<x) res[prime[i]] = x;
            }*/
            two[prime[i]] = x;
        }
    }
    if(L>2){
        if(mp[L]==0)return false;
        else{
            if(res[L]<1) res[L] = 1;
        }
    }

return true;
}
ll pw(ll n,ll p)
{
    ll s = 1;
    for(ll i=1;i<=p;i++) s *= n;
    return s;
}
int main()
{
    seive();
    ll a,b,L,x,y,z;
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mp.clear();
        res.clear();
        ll lcm = 1;
        scanf("%lld %lld %lld",&a ,&b ,&L);
        fact(L);
        if(check(a) and check(b)){
            ll c=0,cnt=0;
            for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it){
                x = it->first;
                y = it->second;
                //cout<<x<<" "<<y<<endl;
                c++;
                if(res[x]<mp[x]){
                    lcm *= pw(x,mp[x]);
                    cnt++;
                }
            }
            //if(cnt==0) lcm=1;
            printf("Case %d: %lld\n",N,lcm);
        }
        else printf("Case %d: impossible\n",N);

    }
    return 0;
}
