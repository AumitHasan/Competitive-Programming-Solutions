#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll unsigned long long int
//#define llu unsigned long long int
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

ll team,ar[100];
long long int g,t,a,d;

void call()
{
    ar[0] = 1;
    for(int i=1;i<=61;i++){
        ar[i] = ar[i-1]*2;
    }
    //cout<<ar[20];
}
int main()
{
    call();

    while(1){
        scanf("%lld %lld %lld %lld",&g,&t,&a,&d);

        if(g==-1 || t==-1 || a==-1 || d==-1) break;

        ll game = (t*(t-1))/2;
        game *= g;
        //cout<<game<<endl;
        team = (g*a) + d;
        //cout<<team<<endl;
        ll x = 0;
        for(int i=0;i<61;i++){
            if(team<=ar[i]){
                x = ar[i];
                //cout<<x<<" "<<i<<endl;
                break;
            }
        }
        //cout<<x<<" "<<t*g<<endl;
        ll add = x - team;

        while(x>0){
            game += x/2;
            //cout<<x/2<<endl;
            x/=2;
        }

        printf("%lld*%lld/%lld+%lld=%llu+%llu\n",g,a,t,d,game,add);

    }
    return 0;
}
