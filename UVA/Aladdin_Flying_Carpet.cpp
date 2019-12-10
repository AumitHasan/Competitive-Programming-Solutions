#include<bits/stdc++.h>
using namespace std;

int main(){

    long T,N=0,i,a,b,c;
    cin>>T;
    while(++N <=T)
    {

        scanf("%ld %ld",&a,&b);
        c=0;
        long root=sqrt(a);
        for(i=b;i<root;i++)
        {
            if(a%i==0)
                c++;
        }

        printf("Case %ld: %ld\n",N,c);
    }


return 0;
}
