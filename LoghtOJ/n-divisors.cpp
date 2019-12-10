#include<bits/stdc++.h>
using namespace std;

#define mx 31623
bitset<mx>mark;
int prime[3401],in=-1;

void seive()
{
    prime[++in] = 2;
    for(int i=3;i<=177;i+=2){
        if(mark[i]==0){
            prime[++in]=i;
            for(int j=i*i;j<=mx;j+=2*i) mark[j]=1;
        }
    }
    for(int i=179;i<=mx;i+=2){
        if(mark[i]==0) prime[++in]=i;
    }
    //cout<<in<<" "<<prime[in];
}
int main()
{
    seive();
    int a,b,num,cnt=0;
    scanf("%d%d%d",&a,&b,&num);
    for(;a<=b;a++){
        int div=1,n = a;
        for(int i=0;i<3401 and prime[i]*prime[i]<=a;i++){
            if(n%prime[i]==0){
                int c=1;
                while(n%prime[i]==0){
                    c++;
                    n/=prime[i];
                }
                div *= c;
                if(div>num) break;
            }
        }
        if(n>1) div*=2;
        if(div==num) cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}
