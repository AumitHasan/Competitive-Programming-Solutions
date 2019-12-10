#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> pr;

#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

#define mx 200007
#define mod 1000000009
#define base 10000007
#define eps 1e-9
#define INF 1llu<<61
#define inf 1<<29
#define PI acos(-1.0) //3.14159.....
////
double angle(double cone){ return (PI * cone) / 180.0;}
//

int n,ar[mx],sz[mx],parent[mx];
vector<pr>adj[mx];
umap<int,int>koi;
umap<int,int>idx;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
    int in = -1;
    for(int i=1;i<=n;i++){
        int num = ar[i];
        if(koi[num]==0){
            if(koi[num-1]){
                int ix = idx[num-1];
                int pos = koi[num-1];
                if(pos==adj[ix].size()){
                    cout<<i<<endl;
                    sz[ix]++;
                    idx[num] = ix;
                    koi[num] = adj[ix].size();

                    parent[num] = adj[ix][adj[ix].size()-1].second;
                    adj[ix].push_back(pr(num,i));

                }
                else {
                    idx[num] = ix;
                    parent[num] = adj[ix][pos-1].second;
                    koi[num] = pos+1;
                }
            }
            else{
                adj[++in].push_back(pr(num,i));
                idx[num] = in;
                koi[num] = 1;
                parent[num] = -1;
                sz[in] = 1;
            }
        }
        cout<<i<<" "<<adj[0].size()<<endl;
    }
    cout<<in<<endl;
    int m=0,idx;
    for(int i=0;i<in;i++){
        cout<<adj[0][i].first<<" ";
    }
    cout<<endl<<idx<<" "<<m<<endl;
}
