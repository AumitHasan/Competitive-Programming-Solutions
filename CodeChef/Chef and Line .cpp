#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll num,n,k,b;
ll a[100007],id[100007],parent[100007];

struct info{
    ll org,eq;
}tail[100007];

ll clc(ll val)
{
    return val*k + b;
}
ll bin(int lo,int hi,int key)
{
    while(hi>lo){
        int mid = (lo+hi)/2;
        if(tail[mid].eq >=key) hi = mid;
        else lo = mid+1;
    }
    return hi;
}
void LIS()
{
    int len=0;
    tail[0].org = a[0];
    tail[0].eq = clc(a[0]);

    for(int i=1;i<n;i++){
        //int pos = lower_bound(tail,tail+len,S[i])-tail;
        if(a[i]<tail[0].org){
            tail[0].org = a[i];
            tail[0].eq = a[i];
        }
        else if(a[i]>=tail[len].eq){
            tail[++len].org = a[i];
            tail[len].eq = clc(a[i]);
        }
        else{
            int ix = bin(0,len,a[i]);
            tail[ix] = a[i];
        }
    }
    cout<<len+1<<endl;
}
int main()
{
    cin>>n>>k>>b;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);

    LIS();

    return 0;
}
