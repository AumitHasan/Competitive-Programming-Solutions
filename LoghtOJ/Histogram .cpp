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

#define mx 30007

int ID,ans,n,ar[mx];

struct info{
    int val,idx;
}tree[mx*3],tmp[mx*3];

void build(int node,int i,int j)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(i==j){
        tree[node].val = ar[i];
        tree[node].idx = i;
        return;
    }

    build(left,i,mid);
    build(right,mid+1,j);

    if(tree[left].val > tree[right].val){
        tree[node].val = tree[right].val;
        tree[node].idx = tree[right].idx;
    }
    else{
        tree[node].val = tree[left].val;
        tree[node].idx = tree[left].idx;
    }
}
int RMQ(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(i>qe || j<qs){
        tmp[node].val = 1e9;
        return 1e9;
    }
    if(i>=qs && j<=qe){
        tmp[node].idx = tree[node].idx;
        tmp[node].val = tree[node].val;
        if(qs==1 && qe==n) return tree[1].idx;
        return tmp[node].val;
    }

    int p1 = RMQ(left,i,mid,qs,qe);
    int p2 = RMQ(right,mid+1,j,qs,qe);

    if(tmp[left].val > tmp[right].val){
        tmp[node].idx = tmp[right].idx;
        tmp[node].val = tmp[right].val;
        ID = tmp[right].idx;
    }
    else{
        tmp[node].idx = tmp[left].idx;
        tmp[node].val = tmp[left].val;
        ID = tmp[left].idx;
    }

    return tmp[1].idx;
}
void solve(int s,int e)
{
    if(s==e) return;
    int id = RMQ(1,1,n,s,e);
    //cout<<"ID: "<<s<<" "<<e<<" "<<id<<endl;
    //cout<<"S: "<<tmp[1].idx<<" "<<tmp[1].val<<endl;
    //cout<<s<<" "<<e<<" "<<id<<endl;
    //getchar();
    //cout<<s<<" "<<e<<" "<<RMQ(1,1,n,s,e)<<endl;
    ans = max(ans,(e-s+1)*ar[id]);
    if(s <= id-1){
        //cout<<s<<" "<<id-1<< " "<<id<<endl;
        solve(s,id-1);
    }
    if(id+1 <= e){
        //cout<<s<<" X "<<id+1<<" "<<e<<endl;
        solve(id+1,e);
    }
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(tree,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        build(1,1,n);
        //cout<<tree[1].idx<<" "<<tree[1].val<<endl;
        ans = 0;
        //cout<<endl<<RMQ(1,1,n,2,3)<<endl;;
        solve(1,n);
        printf("Case %d: %d\n",N,ans);
    }
    return 0;
}
