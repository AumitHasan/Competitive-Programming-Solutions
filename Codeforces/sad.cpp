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

#define mx 1e18

ll tmp,L,R,ar[1000000];
int in;
set<ll>st,s;
set<ll>::iterator it ;

void pre()
{
    ll num,tmp;
    for(int i=1;i<=1e6;i++){
        num = i*i;
        //if(num==1) cout<<1<<endl;
        for(int j=3;j<63;j++){
            if((mx/num) < i) break;
            num *= i;
            tmp = sqrt(num);
            if(num == 1 || tmp*tmp != num) st.insert(num);
        }
    }
    while(st.size()>0){
        num = *st.begin(); st.erase(num);
        ar[++in] = num;

    }
}
int srcL(ll num)
{
    ll ans=-1,mid, lo=1,hi=in;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(ar[mid]>=num){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return ans;
}
int srcR(ll num)
{
    ll ans=-1,mid, lo=1,hi=in;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(ar[mid] <= num){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return ans;
}
int main()
{
    pre();
    for(int i=1;i<11;i++) cout<<ar[i]<<" ";
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%lld %lld",&L,&R);
        tmp = srcR(R) - srcL(L) + 1;
        cout<<srcL(L)<<" "<<srcR(R)<<endl;
        tmp += sqrt(R) - sqrt(L);
        if(sqrt(L)*sqrt(L)==L) tmp++;
        printf("%lld\n",tmp);
    }
}
