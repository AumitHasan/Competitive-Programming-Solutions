#include<bits/stdc++.h>
using namespace std;
#define P 20000000

bool prime[20000000]={false};
long long t_prime[100001];
vector<long long>v;
vector<long long>tp;

void seive(){

    v.push_back(2);
    for(long long i=3;i<=4473;i+=2)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
            for(long long j=i*i;j<P;j+=2*i) prime[j]=true;
        }
    }

    for(long long i=4473;i<P;i+=2)
        if(prime[i]==false) v.push_back(i);

}

int main(){

    seive();
    long long n;
    tp.push_back(0);
    for(long long i=0;i<v.size();i++)
    {
        if(v[i+1]-v[i]==2)  tp.push_back(v[i]);
    }

    while(scanf("%lld",&n)==1)
    {
        printf("(%lld, %lld)\n",tp[n],tp[n]+2);
    }

return 0;
}
