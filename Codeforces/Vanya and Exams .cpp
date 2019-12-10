#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll n,r,avg;

struct info{
    ll marks,essay;
    bool operator<(const info & a) const
    {
        if(essay==a.essay) return marks<a.marks;
        return essay<a.essay;
    }
}ar[100007];

int main()
{
    ll sum=0;
    cin>>n>>r>>avg;
    for(ll i=0;i<n;i++){
        cin>>ar[i].marks>>ar[i].essay;
        sum+=ar[i].marks;
    }
    ll m = avg*n;

    if(sum>=m){
        cout<<0<<endl;
        return 0;
    }
    sort(ar,ar+n);

    sum = m-sum;
    ll in=-1;
    ll res = 0;
    //cout<<sum<<endl;

    while(sum>0 || in<n-1){
        ll pick = min(abs(r-ar[++in].marks),sum);
        //cout<<pick<<" "<<ar[in].marks<<" "<<ar[in].essay<<endl;
        res += pick*ar[in].essay;
        sum-=pick;
    }

    cout<<res<<endl;

    return 0;
}
