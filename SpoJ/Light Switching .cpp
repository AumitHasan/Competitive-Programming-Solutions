#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

struct info{
    int prop,sum;
}tree[MAX * 3];

void update(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        if(tree[node].prop%2) tree[node].sum = (j-i+1) - tree[node].sum;
        //
        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return;

    if(i>=qs && j<=qe){
        tree[node].prop++;
        if(tree[node].prop%2) tree[node].sum = (j-i+1) - tree[node].sum;
        //
        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
        return;
    }

    update(left,i,mid,qs,qe);
    update(right,mid+1,j,qs,qe);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
int query(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        if(tree[node].prop%2) tree[node].sum = (j-i+1) - tree[node].sum;
        //
        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return 0;

    if(i>=qs && j<=qe){
        if(tree[node].prop%2) tree[node].sum = (j-i+1) - tree[node].sum;
        return tree[node].sum;
    }

    int res = 0;
    res += query(left,i,mid,qs,qe);
    res += query(right,mid+1,j,qs,qe);
    return res;
}
int main()
{
    int n,m,s,e,type;
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d %d", &type, &s, &e);
        if(type){
            printf("%d\n",query(1,1,n,s,e));
        }
        else{
            update(1,1,n,s,e);
        }
    }
    return 0;
}
