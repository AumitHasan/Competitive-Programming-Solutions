#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

struct info{
    long long int sum,prop;
}tree[MAX*3];

void update(int node,int i,int j,int qs,int qe,int add)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        tree[node].sum += (j - i + 1) * tree[node].prop;

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return ;

    if(i>=qs && j<=qe){
        tree[node].prop += add;
        tree[node].sum += (j - i + 1) * tree[node].prop;

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;

        return;
    }

    update(left,i,mid,qs,qe,add);
    update(right,mid+1,j,qs,qe,add);

    tree[node].sum = tree[left].sum + tree[right].sum;
    //
}
long long int query(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        tree[node].sum += (j - i + 1) * tree[node].prop;

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return 0;

    if(i>=qs && j<=qe){
        return tree[node].sum;
    }

    long long int s1=0,s2=0;
    s1 = query(left,i,mid,qs,qe);
    s2 = query(right,mid+1,j,qs,qe);

    return s1 + s2;
}
int main()
{

    int T,N=0,type,s,e,n,q,add;
    scanf("%d",&T);
    while(++N<=T){
        mem(tree,0);
        scanf("%d %d", &n, &q);
        printf("Case %d:\n",N);
        while(q--){
            scanf("%d",&type);
            if(type){
                scanf("%d %d", &s, &e);
                printf("%lld\n",query(1,1,n,s+1,e+1));
            }
            else{
                scanf("%d %d %d", &s, &e, &add);
                //cout<<"F"<<endl;
                update(1,1,n,s+1,e+1,add);
            }
        }
    }
    return 0;
}
