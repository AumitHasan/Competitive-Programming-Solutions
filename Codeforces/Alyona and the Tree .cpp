#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define MX 100007
#define MOD 1000000007
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////
ll last;

ll clc(ll s,ll b)
{

    ll tmp=s, pw = 1;
    while(1){
        tmp *= s;
        if(tmp > b){
            last = b - tmp/s ;
            break;
        }
        pw++;
    }
    return pw;
}
int main()
{

    ll x,y;
    cin>>x>>y;

    bool f = false;

    if(x==y){
        cout<<"="<<endl;
        return 0;
    }
    if(x==1 || y==1){
        if(x>y) cout<<">"<<endl;
        else if(x<y) cout<<"<"<<endl;
        return 0;
    }
    if(x==2 && y==3){
        cout<<">"<<endl;
        return 0;
    }
    if(x==3 && y==2){
        cout<<">"<<endl;
        return 0;
    }

    ll a = y;
    ll b = x;

    if(a>b) cout<<">"<<endl;
    else cout<<"<"<<endl;


}
