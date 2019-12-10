#include<bits/stdc++.h>
using namespace std;

#define mod 10e12+7
#define ll long long int
int x[100];

int cnt(int n)
{
    int d,c=-1;
    while(n>0){
        x[++c] = n%10;
        n/=10;
    }
    for(int i=0;i<=c;i++){
        if(x[i]!=1) return 0;
    }
    return c+1;
}
int main()
{
    ll n;
    while(~scanf("%lld",&n)){

        for(int i=1;i<10000;i++){

            ll res = n*i;

        }
    }
    return 0;
}
