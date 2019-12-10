#include<bits/stdc++.h>
using namespace std;

int ar[100007];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);
    sort(ar,ar+n);

    if(ar[n-1]>=ar[n-2]+ar[n-3]) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
