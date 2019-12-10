#include<bits/stdc++.h>

using namespace std ;
vector<long long>v ;
#define INF  1e18
long long a[11000000];
int sum[11000000] ;
int main()
{
    for(long long val= 2;val <= 1000000 ;val++){
        long long cur = val*val ;
        for(long long pwr =3 ; pwr< 63 ; pwr++ ){
                if( ( INF / cur   )< val )break;
                cur = cur*val ;
                if(pwr&1)v.push_back(cur) ;
        }
    }
    sort(v.begin() , v.end()) ;
    a[0] = 0;
    int idx = 0 ;
    for(int i=0 ;i<v.size(); i++  ){
        long long root = sqrt(v[i]) ;
        if(root * root == v[i])continue ;
        if(i < v.size() -1  && v[i] == v[i+1])continue ;
        a[++idx] =v[i] ;
    }
    for(int i=1;i <= idx ; i++ ){
        sum[i] = sum[i-1]  +1 ;
    }
   int qry ;scanf("%d",&qry ) ;
   long long ans =0 ;
   for(int i=1;i<=qry ; i++ ){
        long long l  ,r ;scanf("%lld%lld",&l,&r) ;
        auto lowerIt = lower_bound(a, a+idx +1 , l);
        auto hiIt = upper_bound(a, a+ idx+1, r) ;
        int lowerIndex = lowerIt - a ;
        int higerIndex = hiIt - a ;
        ans = higerIndex - lowerIndex ;
        long long loo = floor(sqrt(l-1)) ;
        long long hii = floor(sqrt(r)) ;

        if(loo *loo == l )loo-- ;
        ans += (hii - loo) ;
        printf("%lld\n",ans) ;
   }
   return 0;
}
