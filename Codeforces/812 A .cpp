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



int main()
{
    int ar[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cin>>ar[i][j];
    }
    bool flag = false;
    //for(int i=0;i<4;i++){
        if(ar[0][3]==1){
            if(ar[1][0] || ar[2][1] || ar[3][2]) flag = true;
        }
        if(ar[1][3]==1){
            if(ar[0][2] || ar[2][0] || ar[3][1]) flag = true;
        }
        if(ar[2][3]==1){
            if(ar[0][1] || ar[1][2] || ar[3][0]) flag = true;
        }
        if(ar[3][3]==1){
            if(ar[0][0] || ar[1][1] || ar[2][2]) flag = true;
        }
    //}
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
