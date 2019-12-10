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

#define mx 10007

ll n,car,road,spot[107],tk[107][107];
bool path[107][107];
umap<string,int>name;


void reset()
{
    name.clear();
    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            if(i==j) tk[i][j] = 0;
            else tk[i][j] = 1e15;
        }
    }
    mem(spot,0);
}
int main()
{
    string A,B,C;
    ll val,cityNum,u,v,test=0;
    while(cin>> n >> car >> road){
        if(!n && !car && !road) break;
        reset();
        //
        cityNum = 0;
        for(int i=0;i<=car;i++){
            cin>>A;
            if(!name[A]) name[A] = ++cityNum;
            if(i==0) continue;
            spot[name[A]]++;
        }
        for(int i=0;i<road;i++){
            cin>>A>>C>>B;
            if(!name[A]) name[A] = ++cityNum;
            if(!name[B]) name[B] = ++cityNum;
            //
            u = name[A]; v = name[B];
            val = 0;
            int len = C.length();
            for(int j=2;j<len-2;j++) val = (val*10) + C[j]-'0';
            //cout<<val<<" ";

            if(C[0]=='<' && C[len-1]=='>'){
                path[u][v] = path[v][u] = 1;
                //adj[u].push_back(v); adj[v].push_back(u);
                tk[u][v] = min(tk[u][v],val); tk[v][u] = min(tk[v][u],val);
                //cout<<1<<endl;
            }
            else if(C[0]=='-'){
                path[u][v] = 1;
                //adj[u].push_back(v);
                tk[u][v] = min(tk[u][v],val);
                //cout<<2<<endl;
            }
            else if(C[len-1]=='-'){
                path[v][u] = 1;
                //adj[v].push_back(u);
                tk[v][u] = min(tk[v][u],val);
                //cout<<3<<endl;
            }
        }

        for(int cc=0;cc<2;cc++){
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(i==j) continue;
                        if(path[i][k] && path[k][j]){
                            tk[i][j] = min(tk[i][j], tk[i][k] + tk[k][j]);
                        }
                    }
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++) cout<<tk[i][j]<<" ";
//            cout<<endl;
//        }
        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(spot[i]){
                ans += spot[i] * tk[1][i];
                ans += spot[i] * tk[i][1];
            }
        }
        printf("%lld. %lld\n",++test,ans);
    }
    return 0;
}
