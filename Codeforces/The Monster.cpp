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

map<int,int>mp;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    for(int i=0;i<1000;i++){
        mp[b+(i*a)]++;
        mp[d+(i*c)]++;
    }


    for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it){
        if(it->second==2){
            cout<<it->first<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
