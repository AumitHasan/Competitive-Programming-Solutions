
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000003
#define mx 1000003

ll fact[mx];

void factoroial()
{
    fact[0]=1;
    for(int i=1;i<mx;i++) fact[i] = (fact[i-1]*i)%mod;

}
ll big_mod(int x,int y)
{
    if(y==0) return 1;
    if(y%2==0){
        ll temp = big_mod(x,y/2);
        return ((temp%mod)*(temp%mod))%mod;
    }
    else return  ( (big_mod(x,y-1)%mod) * (x%mod) ) %mod;
}
int main()
{
    factoroial();
    int n,k,T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d%d",&n,&k);

        int a = (fact[k]%mod*fact[n-k]%mod)%mod;
        int b = big_mod(a,mod-2);
        //cout<<a<<" "<<b<<" "<<fact[n]<<endl;
        ll res = (fact[n]*b)%mod;


        printf("Case %d: %lld\n",N,res);
    }
}
