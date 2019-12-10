#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, cases = 0, x, y, tn, i;
    char cmd[105], name[105][105];
    while(scanf("%d", &n) == 1) {
        map<string, int> R;
        vector<int> g[105];
        int indeg[105] = {};
        for(i = 0; i < n; i++) {
            scanf("%s", name[i]);
            R[name[i]] = i;
        }
        scanf("%d", &m);
        while(m--) {
            scanf("%s", cmd);
            x = R[cmd];
            scanf("%s", cmd);
            y = R[cmd];
            g[x].push_back(y);
            indeg[y]++;
        }
        priority_queue<int, vector<int>, greater<int> > Q;
        for(i = 0; i < n; i++)
            if(indeg[i] == 0)
                Q.push(i);
        printf("Case #%d: Dilbert should drink beverages in this order:", ++cases);
        while(!Q.empty()) {
            tn = Q.top();
            Q.pop();
            for(vector<int>::iterator it = g[tn].begin();
                it != g[tn].end(); it++) {
                int idx = *it;
                indeg[idx]--;
                if(indeg[idx] == 0)
                    Q.push(idx);
            }
            printf(" %s", name[tn]);
        }
        puts(".\n");
    }
    return 0;
}
/*#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

int n,m,vis[mx],color[mx];
string str,ch;
map<string,int>mp;
map<int,string>drink;
vector<int>edge[207];



int main()
{
    int test = 0,sp=0;

    while(~scanf("%d",&n)){
        mem(vis,0);
        mem(color,0);
        mem(edge,0);
        mp.clear();
        drink.clear();
        //
        for(int i=1;i<=n;i++){
            cin>>str;
            mp[str] = i;
            drink[i] = str;
        }
        scanf("%d",&m);
        int u,v;
        for(int i=0;i<m;i++){
            cin>>str>>ch;
            edge[mp[str]].push_back(mp[ch]);
            color[mp[ch]]++;
        }
        //
        printf("Case #%d: Dilbert should drink beverages in this order: ",++test);

        bool ck = false;

        while(1){
            bool flag = false;
            for(int i=1;i<=n;i++){
                if(color[i]==0 && !vis[i]){
                    if(!ck){
                        cout<<drink[i];
                        ck = 1;
                    }
                    else cout<<" "<<drink[i];

                    flag = true;
                    vis[i] = 1;
                    for(int j=0;j<edge[i].size();j++){
                        color[edge[i][j]]--;
                    }
                    break;
                }
            }
            if(!flag) break;
        }
        cout<<"."<<endl<<endl;
    }
}
*/
