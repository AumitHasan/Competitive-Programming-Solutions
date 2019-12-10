#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define pf(a) cout<<a<<endl
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 100007
#define MOD 1000000007
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....

////

int n,m,k,s,goods[mx],cnt[mx];


void bfs
int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for(int i=1;i<=n;i++){
        scanf("%d",&goods[i]);
        cnt[i] = 1;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i] < s){
            bfs(s);
        }
    }
}
