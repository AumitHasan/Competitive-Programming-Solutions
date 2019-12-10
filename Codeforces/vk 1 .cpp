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
#define pii acos(-1.0)

#define mx 100007

llu two[35],three[35];
vector<llu>v;

int main()
{
    v.clear();
    two[0] = three[0] = 1;
    for(int i=1;i<=32;i++){
        two[i] = two[i-1] * 2;
        three[i] = three[i-1] * 3;
    }
    for(int i=0;i<=32;i++){
        for(int j=0;j<=20;j++){
            llu tmp = two[i] * three[j];
            if(tmp<=2e9) v.push_back(tmp);
        }
    }
    //cout<<v.size();
    sort(v.begin(),v.end());
    ll l,r,c=0;
    cin>>l>>r;
    for(int i=0;i<v.size();i++){
        if(v[i]>=l && v[i]<=r) c++;
    }
    cout<<c<<endl;
}
