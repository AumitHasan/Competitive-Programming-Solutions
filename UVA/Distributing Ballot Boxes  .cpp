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

#define mx 500007

int n,B,city[mx];

int check(int lok)
{
    int box = 0;
    for(int i=0;i<n;i++){
        box += city[i] / lok;
        if(city[i] % lok != 0) box++;
    }
    if(box==B) return 1;
    if(box > B) return 2;
    if(box < B) return 3;
}
int main()
{
    while(scanf("%d %d",&n,&B)){
        if(n<0 && B<0) break;
        //
        int tmp,mid,lo = 1, hi = 0,ans=1e9;
        for(int i=0;i<n;i++){
            scanf("%d",&city[i]);
            hi = max(hi,city[i]);
        }
        //
        while(lo<=hi){
            mid = (lo+hi) / 2;
            tmp = check(mid);
            if(tmp == 1){
                ans = min(ans,mid);
                hi = mid - 1;
            }
            else if(tmp == 2) lo = mid + 1;
            else if(tmp == 3){ ans = min(ans,mid); hi = mid - 1;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
