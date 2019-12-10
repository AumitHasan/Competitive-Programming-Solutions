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

int ar[5001];

struct info{
    int a;
    bool operator < (const info& p) const
    {
        return a > p.a;
    }
}P;

int main()
{

    int n,num;
    while(scanf("%d",&n) && n){
        priority_queue<info>Q;

        for(int i=0;i<n;i++){
            scanf("%d",&num);
            P.a = num;
            Q.push(P);
        }

        int x,y;
        ll sum=0;
        while(Q.size()>1){

            info u = Q.top();
            Q.pop();
            x = u.a;

            info v = Q.top();
            Q.pop();
            y = v.a;

            P.a = x+y;
            Q.push(P);
            sum += (x+y);
        }


        cout<<sum<<endl;
    }
    return 0;
}
