#include<bits/stdc++.h>
using namespace std;

#define mx 1299710

bool check[mx];
int prime[100000];

void seive()
{
    prime[0]=2;
    check[0]=check[1]=true;

    for(int i=4;i<mx;i+=2) check[i]=true;
    int in=0;
    for(int i=3;i<=1140;i+=2)
    {
        if(check[i]==false){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) check[j]=true;
        }
    }
    for(int i=1141;i<mx;i+=2)
        if(check[i]==false) prime[++in]=i;

    //cout<<in<<" "<<prime[in]<<endl;
    //cout<<prime[99999]<<endl;
}
int fnd(int i,int j,int n)
{
    if(abs(i-j)==1) return abs(prime[i]-prime[j]);

    int mid = (i+j)/2;

    if(prime[mid]>n) fnd(i,mid,n);
    else if(prime[mid]<n) fnd(mid,j,n);
}
int main()
{
    seive();

    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        if(check[n]==false){
            printf("0\n");
            continue;
        }

        printf("%d\n",fnd(0,99999,n));
    }

return 0;
}
