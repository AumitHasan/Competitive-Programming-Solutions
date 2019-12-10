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
#define pr pair<int, pair<int,int> >
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 100007


map<pr,int>mp;

int T,n,a,b,c,ans,e,f,g;

void solve()
{
    int num,sq,x,y,z;
    for(int i=1;i<=a;i++){
        if(n%i == 0){
            num = n/i;
            sq = sqrt(num);
            for(int j=1;j<=b && j<=sq;j++){
                if(num%j == 0){
                    e = num/j;
                    if(e<=c) ans++;
                    if(e<=b && j<=c && e!=j) ans++;
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        mp.clear();
        ans =  0;
        scanf("%d %d %d %d", &n, &a, &b, &c);
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
