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

bool bin[mx][32];
int n,q,l,r,ar[mx],clc[mx][32],two[32];


void dtob(int pos,int val)
{
    int in=-1;
    while(val>0){
        bin[pos][++in] = val%2;
        val /= 2;
    }
}
void solve()
{
    int one,zero,f,ln = r-l+1;
    int ans=0;
    for(int i=0;i<31;i++){
        one = clc[r][i] - clc[l][i];
        if(bin[l][i]) one++;
        zero = ln - one;
        //cout<<i<<" "<<zero<<" "<<one<<endl;
        if(zero>one) f = 1;
        else f = 0;
        ans += f*two[i];
    }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
        dtob(i,ar[i]);
    }
    //
    for(int i=0;i<31;i++){
        int one = 0;
        for(int j=1;j<=n;j++){
            if(bin[j][i]) one++;
            clc[j][i] = one;
            //cout<<one<<" ";
        }
        //cout<<endl;
    }
    two[0] = 1;
    for(int i=1;i<31;i++) two[i] = two[i-1] * 2;
    //
    while(q--){
        scanf("%d %d",&l,&r);
        solve();
    }
    return 0;
}
