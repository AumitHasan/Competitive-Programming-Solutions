#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

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
#define pii acos(-1.0)

#define mx 100007

int n,u,ar[mx];

int src(int start)
{
    int lo=start,hi=n,ans = start;
    while(lo<=hi){
        int mid = (lo+hi) / 2;
        //cout<<ar[mid]<<" "<<lo<<" "<<hi<<" "<<mid<<endl;
        if(ar[mid]-ar[start]<=u){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    //cout<<"ans: "<<ans<<endl;
    return ans;
}
int main()
{
    double ans = 0.0;
    bool f = 0;
    scanf("%d %d",&n,&u);
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
    for(int i=1;i<=n-2;i++){
        int s = src(i);
        if(s-i>=2){
            f = 1;
            double a = (ar[s]-ar[i+1]);
            double b = (ar[s]-ar[i]);
            ans = max(ans,  a/(b*1.0));
        }
    }
    if(f){
        printf("%.9f\n",ans);
    }
    else{
        cout<<-1<<endl;
    }
}
