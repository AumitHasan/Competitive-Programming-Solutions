#include<bits/stdc++.h>
using namespace std;
#define mx 20009
#define pr pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

int n,root[mx];
bool mark[mx],ck[mx],vis[mx];
set<int>st;
vector<pr>dual;
vector<int>edge[mx];

void bfs(int node,int c)
{
    //cout<<c<<endl;
    queue<int>Q;
    root[node]=c;
    vis[node]=1;
    Q.push(node);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<edge[u].size();i++){
            int v = edge[u][i];
            if(!vis[v]){
                vis[v]=1;
                root[v]=c;
                Q.push(v);
            }
        }
    }
    //cout<<"dkfjlasjflsjlafjas"<<endl;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(vis,0);
        mem(ck,0);
        mem(mark,0);
        mem(edge,0);
        dual.clear();
        st.clear();
        int u,v;

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&u ,&v);
            st.insert(u);
            st.insert(v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        int c=0;
        for(set<int>::iterator it=st.begin();it!=st.end();++it){
            int x = *it;
            //cout<<x<<endl;
            if(vis[x]==0) bfs(x,++c);
        }
        //cout<<"jdklfj"<<endl;
        for(int i=1;i<mx;i++){
            if(edge[i].size()>0){
               dual.push_back(make_pair(edge[i].size(),root[i]));
            }
        }
        sort(dual.begin(),dual.end());
        //cout<<endl;
        int num=0,a,b;
        for(int i=dual.size()-1;i>=0;i--){
            a = dual[i].first;
            b = dual[i].second;
            //cout<<a<< " "<<b<<endl;
            if(ck[b]==false){
                ck[b] = true;
                num+=a;
            }
        }

        printf("Case %d: %d\n",N,num);

    }
}
