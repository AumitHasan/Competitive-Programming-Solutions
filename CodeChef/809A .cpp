#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)
#define M 100009

struct info{
    int a,b;
}ar[M];
struct in{
    int pro,ix,pv;
    bool operator<(const in& a) const
    {
        if(pro>a.pro && (pro+a.pv < pv+a.pro) ){
            return pro < a.pro;
        }
        else if(pro<a.pro && (pro+a.pv > a.pro+pv) ){
            return pro < a.pro;
        }
        return pro>a.pro;

    }
}com[M];

int main()
{
    int f,n,x,sum=0;
    cin>>n>>f;
    for(int i=0;i<n;i++){
        scanf("%d %d",&ar[i].a,&ar[i].b);
        if(ar[i].a*2<=ar[i].b) x = ar[i].a*2;
        else x = ar[i].b;
        com[i].pro = x;
        com[i].ix = ar[i].b;
        com[i].pv = min(ar[i].a,ar[i].b);
        sum += com[i].pv;
     }
     sort(com,com+n);

    //for(int i=0;i<n;i++) cout<<com[i].pro<<" "<<com[i].pv<<endl;

     for(int i=0;i<f;i++){
        sum += com[i].pro;
        sum -= com[i].pv;
     }

     cout<<sum<<endl;

    return 0;
}
