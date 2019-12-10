#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define mx 100007
#define des 2*mx
#define pr pair<int,int>

vector<int>edge[mx];
int n,k,leftw[mx],rightw[mx],vis[des+33];
struct st{
    int a,b,c;
}s;

int bfs(int s)
{
    queue<st>Q;
    Q.push(pr(0,-1));
    while(!Q.empty()){
        pr top = Q.front();
        int u = top.first;
        int lvl = top.second;
        //cout<<"u: "<<u<<" "<<lvl<<endl;
        Q.pop();

        for(int i=0;i<edge[u].size();i++){
            int v = edge[u][i];
            //cout<<v<<" "<<lvl<<endl;
            if(u%n > v%n and vis[v]==0){
                int x = lvl+1;
                if(v%n > x){
                    vis[v]=1;
                    //cout<<"v : "<<v<<" "<<x<<endl;
                    Q.push(pr(v,x));
                    if(v==des or v%n == n-1) return 1;
                }
            }
            else{
                if(v%n > lvl and vis[v]==0){
                    vis[v]=1;
                    //cout<<"vv : "<<v<<" "<<lvl+1<<endl<<endl;
                    Q.push(pr(v,lvl+1));
                    if(v==des or v%n == n-1) return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    cin>>n>>k;
    string s;

    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='X') leftw[i] = 1;
    }
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='X') rightw[i] = 1;
    }

    for(int i=0;i<n;i++){
        if(i==n-1 and leftw[i]==0) edge[i].push_back(des);
        if(leftw[i]==0 and i!=n-1){
            if(leftw[i+1]==0){
                edge[i].push_back(i+1);
                edge[i+1].push_back(i);
            }
            if(rightw[i+k]==0){
                int pos = n+i+k;
                if(i+k>=n) pos=des;
                edge[i].push_back(pos);
            }
        }
    }

    for(int i=0;i<n;i++){

        if(i==n-1 and leftw[i]==0) edge[i+n].push_back(des);

        else if(rightw[i]==0 and i!=n-1){

            if(rightw[i+1]==0){
                edge[n+i].push_back(n+i+1);
                edge[n+i+1].push_back(n+i);
            }
            if(leftw[i+k]==0){
                int pos = i+k;
                if(i+k>=n) pos=des;
                edge[n+i].push_back(pos);
            }
        }
    }

    for(int i=0;i<n*2;i++){
        cout<<i<<" : ";
        for(int j=0;j<edge[i].size();j++) cout<<edge[i][j]<<" ";
        cout<<endl;
    }
    int res = bfs(0);
    if(res==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
