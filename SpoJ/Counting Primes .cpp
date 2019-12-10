#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 1000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int ar[10007];
bool flag[mx];

struct info{
    int up,cnt;
}tree[30007];

void build(int node,int i,int j)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(i==j){
        //tree[node].up = ar[i];
        tree[node].cnt = (flag[ar[i]]) ? 0 : 1;
        return ;
    }
    build(left,i,mid);
    build(right,mid+1,j);

    tree[node].cnt = tree[left].cnt + tree[right].cnt;
}
void update(int node,int i,int j,int qs,int qe,int val)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(tree[node].up != 0){
        tree[node].cnt = (j-i+1) * ( (flag[tree[node].up]) ? 0 : 1 );
        if(i != j){
            tree[left].up = tree[node].up;
            tree[right].up = tree[node].up;
        }
        tree[node].up = 0;
    }

    if(qs>j || qe<i) return ;

    if(i>=qs && j<=qe){
        tree[node].cnt = (j-i+1) * ( (flag[val]) ? 0 : 1 );
        if(i != j){
            tree[left].up = val;
            tree[right].up = val;
        }
        tree[node].up = 0;
        return ;
    }

    update(left,i,mid,qs,qe,val);
    update(right,mid+1,j,qs,qe,val);

    tree[node].cnt = tree[left].cnt + tree[right].cnt;
}
int query(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(tree[node].up != 0){
        tree[node].cnt = (j-i+1) * ( (flag[tree[node].up]) ? 0 : 1 );
        if(i != j){
            tree[left].up = tree[node].up;
            tree[right].up = tree[node].up;
        }
        tree[node].up = 0;
    }

    if(qs>j || qe<i) return 0;

    if(i>=qs && j<=qe){
        return tree[node].cnt;
    }

    int res=0;

    res += query(left,i,mid,qs,qe);
    res += query(right,mid+1,j,qs,qe);
    return res;
}
void seive()
{
    for(int i=4;i<mx;i+=2) flag[i] = 1;
    for(int i=3;i<=1001;i+=2){
        if(!flag[i]){
            for(int j=i*i;j<mx;j+=2*i) flag[j] = 1;
        }
    }
}
int main()
{
    seive();

    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        mem(tree,0);
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

        build(1,1,n);

        printf("Case %d:\n",N);

        int x,y,type,v;
        while(q--){
            scanf("%d",&type);
            if(type){
                scanf("%d %d",&x,&y);
                printf("%d\n",query(1,1,n,x,y));
            }
            else{
                scanf("%d %d %d", &x, &y, &v);
                update(1,1,n,x,y,v);
            }
        }
    }
}

