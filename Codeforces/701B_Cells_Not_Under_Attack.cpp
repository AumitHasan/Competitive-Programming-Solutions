#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
    map<ll,int>row;
    map<ll,int>col;
    vector<ll>v;

    ll n,m,r,c;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>r>>c;
        row[r] = 1;
        col[c] = 1;

        ll a = row.size();
        ll b = col.size();

        ll res = ((a+b)*n)-(a*b);

        v.push_back(n*n-res);
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;

return 0;
}
