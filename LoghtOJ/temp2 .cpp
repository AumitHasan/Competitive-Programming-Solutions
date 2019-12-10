#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b);
}
long long T,a,b,c,l;
int main()
{
    READ("in.txt");
    WRITE("out.txt");

    scanf("%lld",&T);
    for(int cs=1;cs<=T;cs++)
    {
        scanf("%lld %lld %lld",&a,&b,&l);
        a=lcm(a,b);
        if(l%a!=0)cout<<"Case "<<cs<<": impossible\n";
        else
        {
            c=l/a;
            //c *= l/lcm(a,c);
            c *= (a)
            cout<<"Case "<<cs<<": "<<c<<"\n";
        }
    }
    return 0;
}
