#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100007

struct info{
    int cnt,prop,zero,one,two,three;
}tree[MAX * 3];
int ar[MAX];

void build(int node,int i,int j)
{
    if(i==j){
        tree[node].three = 1;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    build(left,i,mid);
    build(right,mid+1,j);

    tree[node].three = tree[left].three + tree[right].three;
}
void solve(int node,int val)
{
    if(val==1){
        swap(tree[node].two,tree[node].three);
        swap(tree[node].one,tree[node].two);
    }
    else if(val==2){
        swap(tree[node].one,tree[node].three);
        swap(tree[node].one,tree[node].two);
    }
}
void update(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        solve(node,tree[node].prop%3);

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }

        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return;

    if(i>=qs && j<=qe){
        tree[node].prop++; // add 1
        solve(node,tree[node].prop % 3);

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }
        tree[node].prop = 0;
        return;
    }


    update(left,i,mid,qs,qe);
    update(right,mid+1,j,qs,qe);

    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
    tree[node].three = tree[left].three + tree[right].three;
}
int query(int node,int i,int j,int qs,int qe)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){
        solve(node,tree[node].prop%3);

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }

        tree[node].prop = 0;
    }

    if(qs>j || qe<i) return 0;

    if(i>=qs && j<=qe){
        return tree[node].three;
    }


    int p1 = query(left,i,mid,qs,qe);
    int p2 = query(right,mid+1,j,qs,qe);

    return p1 + p2;
}
int main()
{

        int n,q,type,qs,qe;
        scanf("%d %d",&n,&q);

        build(1,1,n);
        //cout<<tree[1].cnt<<endl;

        while(q--){
            scanf("%d %d %d", &type, &qs, &qe);
            if(type){
                printf("%d\n",query(1,1,n,qs+1,qe+1));
            }
            else update(1,1,n,qs+1,qe+1);
        }

    return 0;
}

