#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define pf(a)                   cout<<a<<endl
#define sci(a)                  scanf("%d",&a)
#define scii(a, b)              scanf("%d %d",&a, &b)
#define sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define scl(a)                  scanf("%lld", &a)
#define scll(a, b)              scanf("%lld %lld", &a, &b)
#define sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define umap                    unordered_map
#define mem(a,b)                memset(a,b,sizeof(a))
#define IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f)                 freopen(f,"r",stdin)
#define WRITE(f)                freopen(f,"w",stdout)

#define mx                      300009
#define mod                     1000000007
#define base                    10000007
#define eps                     1e-9
#define INF                     1llu<<61
#define inf                     1<<29
#define PI                      acos(-1.0) //3.14159.....

////

string str,ch;
ll ans,res,x,y,ar[mx],n;

int main()
{
    cin>>n>>x>>y;
    cin>>str;
    ch = str[0];
    for(int i=1;i<n;i++){
        if(ch[ch.size()-1] != str[i]) ch += str[i];
    }
    int c = 0;
    for(int i=0;i<ch.size();i++) c += (ch[i]=='0') ? 1 : 0;

    if(!c){
        cout<<0<<endl;
        return 0;
    }
    ans = 1e18;
    if(x<y){
        ans = min(ans, (c-1)*x + y);
    }
    else ans = min(ans, c*y);
    cout<<ans<<endl;

}
