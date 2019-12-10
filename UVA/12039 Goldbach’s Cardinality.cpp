#include<bits/stdc++.h>
using namespace std;

#define mx 10000020

bitset<mx>mark;
long long int prime[664579],cp[mx];

void seive()
{
    int in=-1;
    mark[0]=mark[1]=mark[2]=1;
    for(int i=2;i<mx;i+=2) mark[i]=1;
    for(int i=3;i<=3163;i+=2){
        if(mark[i]==0){
            prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) mark[j]=1;
        }
    }
    int c=0;
    for(int i=1;i<3165;i++){
        if(mark[i]==0){
            cp[i] = ++c;
        }else cp[i] = c;
    }
    for(int i=3165;i<mx-1;i+=2){
        if(mark[i]==0){
            prime[++in]=i;
            cp[i] = ++c;
        }
        else cp[i] = c;
        cp[i+1] = c;
    }
    cp[mx-1]=++c;
    prime[++in] = 10000019;
}
int main()
{
    seive();
    long long int low,high;
    while(1){
        scanf("%lld%lld",&low,&high);
        if(low==0 and high==0) break;
        long long int a,b,c=0,x;
        for(long long int i=0; high-prime[i]>=prime[i] and i<664579;i++){
            if(low-prime[i]>0) a = low-prime[i];
            else a=4;
            b = high-prime[i];
            c += cp[b]-cp[a];
            if(mark[a]==0 and a+a!=low) c++;
            if(a<prime[i]){
                x = cp[prime[i]]-cp[a];
                if(mark[a]==0 and a+a==low) x+=2;
                else if(mark[a]==0) x+=1;
                c-=x;
            }
        }
        printf("%lld\n",c);
    }
    return 0;
}
