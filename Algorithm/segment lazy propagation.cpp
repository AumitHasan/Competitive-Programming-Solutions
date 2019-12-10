#include<bits/stdc++.h>
using namespace std;

#define MAX 100007

int ar[MAX];
struct info{
    int prop,sum;
}tree[MAX * 3];

void build(int node,int i,int j)
{
    if(i==j){
        tree[node].sum = ar[i];
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    build(left,i,mid);
    build(right,mid+1,j);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
void update(int node,int i,int j,int qs,int qe,int value)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){ // This node needs to be updated
        tree[node].sum += (j - i + 1) * tree[node].prop; // Update

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }

        tree[node].prop = 0; // reset
    }

    if(qs>j || qe<i) return;

    if(i>=qs && j<=qe){ // in range
        tree[node].sum += (j - i + 1) * value;

        if(i != j){
            tree[left].prop += value;
            tree[right].prop += value;
        }
        return;
    }


    update(left,i,mid,qs,qe,value);
    update(right,mid+1,j,qs,qe,value);

    tree[node].sum = tree[left].sum + tree[right].sum + (j - i + 1)*tree[node].prop;
}
int query(int node,int i,int j,int qs,int qe,int carry)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){  // This node needs to be updated
        tree[node].sum += (j - i + 1) * tree[node].prop; // update

        if(i != j){
            tree[left].prop += tree[node].prop;
            tree[right].prop += tree[node].prop;
        }

        tree[node].prop = 0; // reset
    }
    if(qs>j || qe<i) return 0;

    if(i>=qs && j<=qe){
        return tree[node].sum + carry*(j - i + 1);//previous propagate value in carry
    }


    int p1 = query(left,i,mid,qs,qe,carry + tree[node].prop);
    int p2 = query(right,mid+1,j,qs,qe,carry + tree[node].prop);

    return p1 + p2;
}
int main()
{
    ar[1] = ar[2] = ar[3] = ar[4] = 1;
    build(1,1,4);

    cout<<query(1,1,4,2,4,0)<<endl;
    update(1,1,4,3,4,1);
    cout<<query(1,1,4,2,4,0)<<endl;

    return 0;
}
