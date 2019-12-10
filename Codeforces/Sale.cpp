#include<iostream>
using namespace std;

int main(){

    int n,m,i,sum=0,c;
    cin>>n>>m;
    int a[n+1];
    a[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
        {
            sum+=a[i];
            c++;
            if(c==m)
                break;
        }
    }
    sum*=-1;
    cout<<sum<<endl;


return 0;
}
