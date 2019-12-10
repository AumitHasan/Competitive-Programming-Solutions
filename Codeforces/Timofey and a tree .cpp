#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////

int u,v,n,x,ar[mx],ans;

vector<int>kaj,adj[mx];
set<int>st;



void call(int u,int par,int color)
{
    //if(adj[u].size()==1) return;

    for(auto v: adj[u]){
        if(v==par) continue;

        if(ar[v] != color){
            ans = 0;
            return;
        }
        call(v,u,color);

    }
}
void dfs(int u,int par)
{
    for(auto v: adj[u]){
        if(v==par) continue;
        if(ar[u] != ar[v]){
            st.insert(u);
            st.insert(v);
        }
        dfs(v,u);
    }
}
int main()
{
    sci(n);
    for(int i=1;i<n;i++){
        scii(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        sci(x);
        ar[i] = x;
    }
    dfs(1,1);
    if(st.size()==0){
        pf("YES");
        pf(1);
        return 0;
    }
//    while(st.size()){
//        cout<<*st.begin()<<endl;
//        st.erase(*st.begin());
//    }
    for(int i=1;i<=5;i++){
        if(st.size()){
            int cur = *st.begin(); st.erase(cur);
            if(adj[cur].size()>2) continue;
            ans = 1;
            //cout<<cur<<endl;
            call(cur,cur,ar[adj[cur][0]]);
            if(ans){
                pf("YES");
                pf(cur);
                return 0;
            }
        }
    }
    pf("NO");

    return 0;
}
