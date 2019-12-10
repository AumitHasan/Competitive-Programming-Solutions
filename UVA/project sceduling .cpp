#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 50
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

int somoi[mx],deg[mx],ans[mx],in;
vector<int>edge[mx];
map<string,int>mp;


void dfs(int u,int val)
{
    ans[u] = val;

    for(int i=0;i<edge[u].size();i++){
        int v = edge[u][i];
        if(val + somoi[v] > ans[v]){
            ans[v] = val + somoi[v];
            dfs(v,ans[v]);
        }
    }
    return ;
}
void topsort()
{
    for(int i=1;i<=in;i++){
        if(deg[i]==0){
            dfs(i,somoi[i]);
        }
    }
    int res = 0;
    for(int i=1;i<=in;i++) res = max(res,ans[i]);
    cout<<res<<endl;
}
int main()
{

    string tmp,str,ch="x ",s,e;
    //char str[100];

    int T,cost;
    cin>>T;
    cin.ignore();
    cin.ignore();

    for(int test=0;test<T;test++){
        mp.clear();
        mem(edge,0);
        mem(deg,0);
        mem(somoi,0);
        mem(ans,0);
        //
        in = 0;
        //
        while(1){
            getline(cin,str);
            //gets(str);
            if(str.length() ==0) break;
            s = "";
            e = "";
            for(int i=0;i<str.size();i++){
                if(str[i] == ch[1]){
                    cost = 0;
                    for(int j=i+1;j<str.size();j++){
                        if(str[j]==ch[1]){
                            for(int k=j+1;k<str.size();k++) e += str[k];
                            break;
                        }
                        cost = (cost*10) + str[j]-'0';
                    }

                    break;
                }
                s += str[i];
            }
            //
            if(!mp[s]) mp[s] = ++in;
            int id = mp[s];
            somoi[id] = cost;
            for(int i=0;i<e.size();i++){
                tmp = e[i];
                if(mp[tmp]==0) mp[tmp] = ++in;
                int ix = mp[tmp];
                edge[ix].push_back(id);
            }
            //
            deg[id] += e.size();
        }
//        for(int i=1;i<=6;i++){
//            for(int j=0;j<edge[i].size();j++) cout<<edge[i][j]<<" ";
//            cout<<endl;
//        }
        if(test>0) cout<<endl;
        topsort();
    }
}
