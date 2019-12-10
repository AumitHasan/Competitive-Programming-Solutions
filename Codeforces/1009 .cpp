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

#define     mx                      100007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////
bool flag[mx];
string str,ans="";

string o(int x)
{
     string s="";
     for(int i=0;i<x;i++) s += "1";
     return s;
}
string z(int x)
{
     string s="";
     for(int i=0;i<x;i++) s += "0";
     return s;
}
string t(int x)
{
     string s="";
     for(int i=0;i<x;i++) s += "2";
     return s;
}
int main()
{

    cin>>str;

    int one=0,two=0,zero=0,cur=str.size();


    for(int i=0;i<str.size();i++){
        if(str[i]=='2'){
            cur = i; break;
        }
        if(str[i]=='0') zero++;
        else one++;
    }
    ans += z(zero);
    ans += o(one);

    int c = 0;
    for(int i=cur;i<str.size();i++) c += (str[i]=='1') ? 1 : 0;
    ans += o(c);

    for(int i=cur;i<str.size();i++){
        if(str[i]=='1') continue;
        ans += str[i];
    }
    cout<<ans<<endl;
}
