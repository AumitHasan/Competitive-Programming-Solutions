#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define ll long long int


#define mx 100007

ll ar[mx],lo=1e10;
ll v[100007];

int main()
{
    long long int x,y,n,sum=0,dif,in=-1;
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",&ar[i]);
    sort(ar,ar+n);
    for(int i=1;i<n;i++){
        in++;
        x = ar[i-1];
        y = ar[i];
        if(y<0){
            lo = min(lo,abs(y-x));
            dif = abs(y-x);
            v[in] = (dif);
            sum+=dif;
        }
        else if(y==0){
            lo = min(lo,abs(x));
            dif = abs(x);
            v[in] = (dif);
            sum += dif;
        }
        else if(x<0 && y>0){
            lo = min(lo, abs(x)+y);
            dif = abs(x)+y;
            v[in] = (dif);
            sum += dif;
        }
        else{
            lo = min(lo,y-x);
            dif = y-x;
            v[in] = (dif);
            sum += dif;
        }
        //cout<<dif<<endl;
    }
    //
    ll ans = 0;
    for(int i=0;i<=in;i++){
        if(lo==v[i]) continue;
        if(v[i]%lo != 0){
            printf("%lld\n",sum);
            return 0;
        }
        ans += v[i] / lo;
        ans--;
    }
    printf("%lld\n",ans);



}
