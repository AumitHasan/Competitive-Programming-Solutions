#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define m 1000

int main()
{
    ll n;
    cin>>n;

    ll house = 1234567;
    ll car = 123456;
    ll com = 1234;
    ll res,x,y,c;

    for(int k=0;k<=m;k++)
    {
        res=0;
        res = k*car;
        for(int i=0;i<=100;i++)
        {
            x=0;
            x = house*i;
            for(int j=0;j<=m;j++)
            {
                y=0;
                y = com*j;

                if(n-x-y==res){
                    printf("YES\n");
                    return 0;
                }
                if((x+y)>n){  break;}
            }

        }

    }

    printf("NO\n");

return 0;
}
