#include<bits/stdc++.h>
using namespace std;
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define lim 2147483649
#define mx 46355

bitset<mx>mark;
int prime[4794];
long long ar[100009];
bool ck[100009];

void seive()
{
    int in=-1;
    prime[++in] = 2;
    for(int i=3;i<=218;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=219;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
   // cout<<in<<endl;
}
int main()
{
    seive();
    int T,N=0;
    long long a,b;
    scanf("%d",&T);
    while(++N<=T){
        //memset(ck,0,sizeof(ck));
        int hi;
        scanf("%lld %lld",&a ,&b);
        if(a==1) ck[0] = 1;
        for(int i=0;a<=b;i++){
            ar[i] = a++;

            hi = i;
        }
        //cout<<hi<<endl;
        for(int j=0;j<4794 && prime[j]*prime[j]<=b;j++){
            int c = 0;
            //cout<<prime[j]<<endl;
            if(prime[j]>ar[0]){
                c = (prime[j]-ar[0])+prime[j];
            }
            else if(ar[0]==prime[j]){
                c = prime[j];
            }
            else{
                if(ar[0]%prime[j]==0) c = 0;
                else c = prime[j]-(ar[0]%prime[j]);
            }
            //cout<<c<<endl;
            //if(ar[c]==prime[j]) c += prime[j];
            for(int i=c;i<=hi;i+=prime[j]) ck[i] = 1;
        }
        //if(a==1) ck[0] = 1;
        int cnt=0;

        for(int i=0;i<=hi;i++){
            if(ck[i]==0) cnt++;
            else ck[i] = 0;

        }
        printf("Case %d: %d\n",N,cnt);
    }
}
