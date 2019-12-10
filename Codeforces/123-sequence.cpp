#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[3]={0};
    int n,s;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&s);
        a[s-1]++;
    }
    sort(a,a+3);
    cout<<a[0]+a[1]<<endl;

    return 0;
}
