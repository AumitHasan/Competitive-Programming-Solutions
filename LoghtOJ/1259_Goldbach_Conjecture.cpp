#include<bits/stdc++.h>
using namespace std;

#define mx 10000001

bool check[mx];
int prime[664579];

void seive()
{
    int in=-1;
    prime[++in]=2;

    check[0]=check[1]=true;
    for(int i=4;i<mx;i+=2) check[i]=true;

    for(int i=3;i<=3162;i+=2)
    {
        if(check[i]==false){
            prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) check[j]=true;
        }
    }
    for(int i=3163;i<mx;i+=2)
        if(check[i]==false) prime[++in]=i;

    //cout<<in<<" "<<prime[in]<<endl;
}
int main()
{
    seive();
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        int c=0,a,b,num,temp;
        scanf("%d",&num);

        for(int i=0;prime[i]<=num/2;i++)
        {
            temp=0;
            temp = num-prime[i];

            if(check[temp]==false) c++;
        }

        printf("Case %d: %d\n",N,c);
    }

return 0;
}
