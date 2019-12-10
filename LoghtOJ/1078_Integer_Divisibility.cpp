#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N=0,T;
    cin>>T;
    while(++N <=T)
    {
        long long n,d,i,a;
        cin>>n>>d;
        a=d;
        printf("Case %d: ",N);

        for(i=1;;i++)
        {
            if(d%n==0)
                break;

            d=d%n;
           // cout<<d<<" ";
            d=(d*10)+a;
           // cout<<d<<" "<<i<<endl;
        }

        cout<<i<<endl;


    }


return 0;
}
