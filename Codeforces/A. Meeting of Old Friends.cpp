#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

int main()
{
    ll l1,l2,r1,r2,k,m=0,x,y;
    cin>>l1>>r1>>l2>>r2>>k;

    if(l1==r1 and r1==l2 and l2==r2 and k==r2) m=0;
    else if(l1==r1 and r1==l2 and l2==r2) m=1;
    else if(l2>=l1 and l2<=r1){
        x = l2;
        if(l1>l2) x=l1;
        y = min(r1,r2);

        m = y-x+1;
        if(k>=x and k<=y) m--;
    }
    else if(l2<l1 and r2>=l1){
        x = l1;
        y = r2;
        if(r2>r1) y = r1;
        m = y-x+1;
        if(k>=x and k<=y) m--;
    }

    cout<<m<<endl;
}
