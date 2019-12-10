#include<bits/stdc++.h>
using namespace std;


int main()
{
    int c=0,ar[10000],n;

    cin>>n;
    for(int i=0;i<n;i++) cin>>ar[i];

    for(int i=1;i<n-1;i++){
        if((ar[i]>ar[i-1] && ar[i]>ar[i+1]) || (ar[i]<ar[i-1] && ar[i]<ar[i+1]))
            c++;
    }
    cout<<c<<endl;
}
