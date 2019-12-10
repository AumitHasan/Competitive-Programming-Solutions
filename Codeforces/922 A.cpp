#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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

#define mx 100007


int main()
{
    ll cpy,org;
    cin>>cpy>>org;
    if(cpy==0 && org==1){
        cout<<"Yes"<<endl;
        return 0;
    }
    ll tmp = org - 1;
    if(tmp<0 || cpy==0){
        cout<<"No"<<endl;
        return 0;
    }
    tmp = cpy - tmp;
    if(tmp<0){
        cout<<"No"<<endl;
        return 0;
    }
    if(tmp%2==0){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}
