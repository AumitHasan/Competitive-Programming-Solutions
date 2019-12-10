#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)


double ncr(ll n,ll r)
{
    if(n-r>r) r = n-r;
    double ans=1.0,x=1;
    for(double i=r+1;i<=n;i++){
        ans = (ans*i);
        ans/=x;
        x++;
    }
    return ans;
}
int main()
{
    ll n,x,m,h,sum = 0,dept;

    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        scanf("%lld",&x);
        sum += x;
        if(i==h-1) dept = x;
    }

    if(sum<n){
        cout<<-1<<endl;
        return 0;
    }

    sum--;
    n--;
    dept--;

    double ttl = ncr(sum,n);

    double res=0.0;

    for(int i=1;i<=min(n,dept);i++){
        if(sum-dept>=n-i)
            res += ncr(dept,i) * ncr(sum-dept,n-i);
    }
    res = res / ttl;

    printf("%.6f\n",res);
}
