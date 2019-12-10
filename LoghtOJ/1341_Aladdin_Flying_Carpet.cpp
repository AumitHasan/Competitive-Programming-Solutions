#include<bits/stdc++.h>
using namespace std;

bool prime[1000007];
vector <long long> v;

void seive(){
    int i,j;
    v.push_back(2);
    for(i=3;i<=1000;i+=2)
        if(prime[i]==false){
            v.push_back(i);
            for(j=i*i;j<1000007;j+=2*i)  prime[j]=true;
        }
    for(j=1001;j<1000007;j+=2)
        if(prime[j]==false) v.push_back(j);
}
int main(){
    int T,N=0;
    seive();
    scanf("%d",&T);
    while(++N <=T)
    {
        long long a,b,i,num;
        int div=1;
        scanf("%lld %lld",&a,&b);
        num=a;
        for(i=0;i<=v.size()&&v[i]*v[i]<=a;i++)
        {
            if(a%v[i]==0)
            {
                int c = 1;
                while(a%v[i]==0)
                {
                    a/=v[i];
                    c++;
                }
                div*= c;
            }
        }
        if(a>1) div*=2;
        div/=2;
        printf("Case %d: ",N);
        if(b>=sqrt(num)) printf("0\n");
        else{
            for(i=1;i<b;i++)
                if(num%i==0) div--;
             printf("%d\n",div);
        }
    }
return 0;
}
