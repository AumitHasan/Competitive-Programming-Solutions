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

#define mx 1007

int n,f=0,z=0,tmp;
struct info{
    int num,five,zero;
}x;

void bfs()
{
    queue<info>Q;
    x.num=5; x.five=f-1; x.zero=z;
    par[]
    Q.push(x);
    while(!Q.empty())
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==5) f++;
        else z++;
    }
    bfs();
}
