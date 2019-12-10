#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mx 103
#define mem(a,b) memset(a,b,sizeof(a))

ll n,ar[mx][mx],mark[mx];
struct st{
    int x,y;
}student[mx];
struct stt{
    int x,y;
}teacher[mx];

bool ck(ll val)
{
    val = 2;
    mem(mark,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ar[i][j]<=val) mark[j]++;
        }
    }
    sort(mark,mark+n+1);
    for(int i=1;i<=n;i++) cout<<mark[i]<<" ";
    //getchar();
    int c = 0,m=n;
    for(int i=1;i<=n;i++){

        if(mark[i]<i) break;
        c++;
        //cout<<mark[i]<<" ";

    }
    //cout<<endl;
    if(c==n) return 1;
    return 0;
}
int main()
{
    mem(ar,-1);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&student[i].x,&student[i].y);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&teacher[i].x,&teacher[i].y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ar[i][j] = abs(student[i].x - teacher[j].x) + abs(student[i].y - teacher[j].y);
        }
    }
    ll lo=0,hi=10e10,ans=0;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(ck(mid)){
            return 0;
            ans = mid;
            hi = mid-1;
            cout<<"ans: "<<ans<<endl;

        }
        else{
            lo = mid + 1;
        }
        cout<<"lo/hi: "<<lo<<" "<<hi<<endl;
    }
    cout<<ans<<endl;
}
