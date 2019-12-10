#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)



int main()
{
    ll num,pos,even,odd;
    cin>>num>>pos;

    if(num%2==0){
        even = num/2;
        odd = num/2;
    }
    else{
        odd = num/2 + 1;
        even = num/2;
    }

    if(pos<=odd){
        cout<<(pos*2)-1<<endl;
    }
    else{
        pos = pos - odd;
        cout<<pos*2<<endl;
    }
}
