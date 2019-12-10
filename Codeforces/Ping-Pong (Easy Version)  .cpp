#include<stdio.h>
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

int vis[109],n,type,in,a,b,src,des;
vector<pr>v;

void query()
{
    mem(vis,0);
    queue<int>Q;
    Q.push(src);
    vis[src] = 1;
    while(!Q.empty()){
        int x = Q.front();  Q.pop();
        a = v[x].first;
        b = v[x].second;
        for(int i=1;i<=in;i++){
            int c = v[i].first;
            int d = v[i].second;
            if(vis[i]==0){
                if((a>c && a<d) || (b>c && b<d)){
                    vis[i] = 1;
                    if(i==des){
                        cout<<"YES"<<endl;
                        return;
                    }
                    Q.push(i);
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
    v.push_back(pr(0,0));

    scanf("%d",&n);
    while(n--){
        scanf("%d",&type);
        if(type==1){
            scanf("%d %d",&a,&b);
            v.push_back(pr(a,b));
            in++;
        }
        else{
            scanf("%d %d",&src,&des);
            query();
        }
    }
}
