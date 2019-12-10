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
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)

#define     mx                      400007
#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....

////

int n,d,k;
vector<int>adj[mx];
set<int>st;

int main()
{
    sciii(n,d,k);

    if(n==1 || n<=d){
        cout<<"NO"<<endl;
        return 0;
    }
    if(n==2){
        if(d==1){
            cout<<"YES"<<endl;
            cout<<1<<" "<<2<<endl;
            return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    if(k<2){
        cout<<"NO"<<endl;
        return 0;
    }
    //

    for(int i=1;i<=d;i++){
        adj[i].push_back(i+1);
    }
    int deg,cur = d+1;
    int last = d + 1;

    for(int i=2;i<=d;i++){
        if(cur==n) break;

        deg = min(abs(1-i),abs(i-last));
        queue<pr>Q;
        for(int j=3;j<=k;j++){
            if(cur==n) break;
            Q.push(pr(++cur,1));
            adj[i].push_back(cur);
        }

        if(cur==n) break;

        while(!Q.empty()){
            pr u = Q.front(); Q.pop();
            if(cur==n) break;

            if(u.second >= deg) continue;

            for(int i=2;i<=k;i++){
                Q.push(pr(++cur,u.second+1));
                adj[u.first].push_back(cur);
                if(cur==n) break;
            }
        }
    }
    int c = 0;
    for(int i=1;i<=n;i++){
        st.insert(i);
        //cout<<i<<" : ";
        for(int j=0;j<adj[i].size();j++){
            st.insert(adj[i][j]);
            c++;
            //cout<<adj[i][j]<<" ";
        }
        //cout<<endl;
    }
    if(c==n-1 && st.size()==n){
        cout<<"YES"<<endl;

        for(int i=1;i<=n;i++){
            for(int j=0;j<adj[i].size();j++){
                printf("%d %d\n",i,adj[i][j]);
            }
        }
    }
    else{
        cout<<"NO"<<endl;
    }
}
