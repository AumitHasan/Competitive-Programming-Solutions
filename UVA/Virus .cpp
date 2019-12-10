#include<bits/stdc++.h>
using namespace std;

#define mx 1048579
#define mem(a,b) memset(a,b,sizeof(a))

const int N = (1<<20) + 10;
int n,l[N],r[N],ans;

void dfs(int u,int d)
{
    if(l[u]==0 || r[u]==0){
        if(d<ans) ans = d;
    }
    else{
        dfs(l[u],d+1);
        dfs(r[u],d+1);
    }
}
int main()
{

    int n,a,b;
    while(scanf("%d",&n) != EOF){
        for(int i=1;i<=n;i++) scanf("%d %d",&l[i],&r[i]);
        ans = n;
        dfs(1,1);
        printf("%d\n",ans);
    }
    return 0;
}
