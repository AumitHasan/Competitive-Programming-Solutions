#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int i=0;i<n;i++)
    {
        int x=0;
        if(i==0){
           x = a[i]-1;
           if(x>=15){cout<<"15"<<endl; return 0;}
        }else   x = a[i]-a[i-1];

        if(x>15){ cout<<a[i-1]+15<<endl; return 0;}
    }
    if(a[n-1]<90){
        int x = 90-a[n-1];
        if(x>15){
            cout<<a[n-1]+15<<endl; return 0;
        }
    }
    cout<<"90"<<endl;

return 0;
}
