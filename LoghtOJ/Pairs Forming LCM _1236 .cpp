#include<bits/stdc++.h>
using namespace std;
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define mx 10000001

bitset<mx>mark;
int prime[664579];

void seive()
{
    int in=-1;
    prime[++in] = 2;
    for(int i=3;i<=3163;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=3165;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }
    //cout<<in<<" "<<prime[in]<<endl;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    seive();
    int T,N=0;
    long long x,pw;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%lld",&x);

        int c,in=-1;
        pw = 1;
        for(int i=0;i<664579 && prime[i]*prime[i]<=x;i++){
            if(x%prime[i]==0){
                c=0;
                while(x%prime[i]==0){
                    c++;
                    x/=prime[i];
                }
                pw *= c*2 + 1;
            }
        }

        if(x>=2){
           pw *= 3;
        }

        printf("Case %d: %lld\n",N,(pw/2)+1);


    }
    return 0;
}


