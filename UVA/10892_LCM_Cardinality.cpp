#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool prime[44722];
int op[4648];

void seive()
{
    int in=-1;
    op[++in]=2;
    memset(prime,0,sizeof(prime));
    for(int i=3;i<=211;i+=2)
    {
        if(prime[i]==false){
            op[++in]=i;
            for(int j=i*i;j<=44721;j+=2*i) prime[j]=true;
        }
    }
    for(int i=213;i<=44721;i+=2)
        if(prime[i]==false) op[++in]=i;


}

int main()
{
        seive();
        while(1)
        {
            ll n,num;
            scanf("%lld",&n);
            if(n==0) break;
            num=n;

            ll div=1,f=0,mx=0;
            for(ll i=0;i<4648&&op[i]*op[i]<=n;i++)
            {
                if(n%op[i]==0){
                    f++;
                    int c=1;
                    while(n%op[i]==0){
                        c++;
                        n/=op[i];
                    }
                    if(c-1>mx) mx=c-1;
                    div*=c;
                }
            }
            if(n>=2) { div*=2; f++;}
            cout<<"d: "<<div<<" "<<mx<<endl;
            ll res=div;
            if(f>1) res+= mx;

            cout<<num<<" "<<res<<endl;
        }
return 0;
}
