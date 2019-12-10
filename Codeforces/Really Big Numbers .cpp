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

ll n,s;

ll ss(ll num)
{
    ll sum=0;
    while(num>0){
        sum += num%10;
        num/=10;
    }
    return sum;
}
int main()
{
    cin>>n>>s;
    ll sum=0,res,num,lo=0,hi=n+100,x=0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        sum = ss(mid);
        if(mid-sum>=s){
            res = mid;
            hi=mid-1;
        }
        else lo = mid+1;
    }
    res = n-res+1;
    cout<<max(res,x)<<endl;
}
