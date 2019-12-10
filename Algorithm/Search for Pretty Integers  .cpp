#include<bits/stdc++.h>
using namespace std;

int ar[100],e[10],f[10];

int main()
{
    int n,m,x,a=10,b=10;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>x;
        a = min(a,x);
        e[x] = 1;
    }

    for(int i=0;i<m;i++){
        cin>>x;
        b = min(b,x);
        f[x] = 1;
    }

    for(int i=1;i<10;i++){
        ar[i] = e[i] + f[i];
    }
    for(int i=1;i<10;i++){
        if(ar[i]>1){
            cout<<i<<endl;
            return 0;
        }
    }
    //
    if(a>b) swap(a,b);

    cout<<(a*10) + b<<endl;
}
