#include<bits/stdc++.h>
using namespace std;

struct info{
    int a,b;
    bool operator<(const info& p) const
    {
        if(b==p.b) return a<p.a;
        return b<p.b;
    }
}ar[1000009];

int main()
{
    int n,k,x,y;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);

    for(int i=0;i<n;i++){
        ar[i].a = a[i];
        ar[i].b = b[i]-a[i];
    }
    sort(ar,ar+n);

    int in=0,sum=0;
    for(int i=n-1;i>=0;i--){
        in++;
        if(in>k){
            if(ar[i].b<0) sum += ar[i].a + ar[i].b;
            else sum += ar[i].a;
        }
        else sum += ar[i].a;

    }

    cout<<sum<<endl;
    return 0;
}
