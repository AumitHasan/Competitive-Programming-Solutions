#include<bits/stdc++.h>
using namespace std;
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define lim 2147483649
#define mx 65601

bitset<mx>mark;
int prime[6552];
long long ar[100009],bs[1000],pw[1000];
bool ck[100009];

void seive()
{
    int in=-1;
    prime[++in] = 2;
    for(int i=3;i<=259;i+=2){
        if(mark[i]==0){
            prime[++in] = i;
            for(int j=i*i;j<mx;j+=2*i) mark[j] = 1;
        }
    }
    for(int i=261;i<mx;i+=2){
        if(mark[i]==0) prime[++in] = i;
    }


    //cout<<v<<endl;
   //cout<<in<<" "<<prime[in]<<endl;
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");
    seive();
    int T,N=0;
    long long x;
    scanf("%d",&T);
    while(++N<=T){
        int sign = 0;
        bool flag = false;
        scanf("%lld",&x);
        if(x<0){
            sign = 1;
            x *= -1;
        }
        int c = 0,in=-1;
        for(int i=0;i<6552 && prime[i]*prime[i]<=x;i++){
            if(x%prime[i]==0){
                c=0;
                while(x%prime[i]==0){
                    c++;
                    x/=prime[i];
                }
                bs[++in] = prime[i];
                pw[in] = c;
            }
        }

        if(x>=2){
           bs[++in] = x;
           pw[in] = 1;
        }

        int com=1000000;
        for(int i=0;i<=in;i++){
            if(pw[i]<com) com = pw[i];
        }
        for(int i=0;i<=in;i++){
            if(pw[i]%com!=0){
                flag = true;
            }
        }

        if(flag) printf("Case %d: 1\n",N);
        else{
            while(sign && com%2==0){
                com/=2;
            }
            printf("Case %d: %d\n",N,com);
        }

    }
    return 0;
}

