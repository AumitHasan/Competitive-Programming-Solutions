#include<iostream>
using namespace std;

int main(){

    int i,c,cnt=0,j,f,l,n;
    cin>>n;
    int a[n+1];
    a[0]=0;

    for(i=1;i<=n;i++)
        cin>>a[i];

    if(n==2)
    {
        f=1;
        l=2;
    }
    else{
        for(i=1;i<=n;i++)
        {
            j=i+1;
            if(j>n)
                j=1;

            c=a[i]-a[j];
            if(c<0)
                c*=-1;

            if(i==1)
            {
                  cnt=c;
                  f=i;
                  l=j;
            }
            else if(c<cnt)
            {
                  cnt=c;
                  f=i;
                  l=j;
            }


        }

    }
    cout<<f<<" "<<l<<endl;

return 0;
}
