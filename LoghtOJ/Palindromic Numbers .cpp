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


#define     mx                      100007

////

ll a,b,l,r,res,dp[19][19][2];
vector<int>vec;



ll call(int i,int j,int flag)
{
    cout<<i<<" "<<j<<" "<<flag<<endl;


    if(i>j) return 1;
    if(dp[i][j][flag] != -1) return dp[i][j][flag];

    ll ans = 0;
    int lim = 9;
    if(flag) lim = min(vec[i],vec[j]);
    cout<<"lim: "<<lim<<endl;

    bool check = false;

    for(int st=0;st<=lim;st++){
        if(flag && st==lim) check = true;

        ans += call(i+1,j-1,check);
    }
    return dp[i][j][flag] = ans;
}
void cnv(ll num)
{

    while(num>0){
        vec.push_back(num%10);
        num/=10;
    }
    reverse(vec.begin(),vec.end());
    //for(auto x : vec) cout<<x<<endl;
}
void solve()
{
    l--;
    //bool f=true;
    if(l>9 && l%10==0){
        a = l--;

    }
    else a = l;

    cnv(a);
    mem(dp,-1);
    //cout<<"ff<<endl;
    res = call(0,vec.size()-1,1);
}
int main()
{
    int T,N=0;
    sci(T);
    while(++N<=T){
        scll(l,r);
        //if(l>r) swap(l,r);
        solve();
        printf("%lld\n",res);
    }
    return 0;
}
