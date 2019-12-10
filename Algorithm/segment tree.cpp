#include<bits/stdc++.h>
using namespace std;

#define MAX 100007

int ar[MAX],tree[MAX*3];

void build(int node,int i,int j)
{
    if(i> j) return ;

    if(i==j){
        tree[node] = ar[i];
        return ;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    build(left,i,mid);
    build(right,mid+1,j);

    tree[node] = tree[left] + tree[right];
}
void update(int node,int i,int j,int idx,int value)
{
    if(i > j || i>idx || j<idx) return ;
    if(i == j){
        tree[node] = value;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    update(left,i,mid,idx,value);
    update(right,mid+1,j,idx,value);

    tree[node] = tree[left] + tree[right];
}
int query(int node,int i,int j,int s,int e)
{
    if(i>e || j<s) return 0;
    if(i>=s && j<=e){
        return tree[node];
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    int p1 = query(left,i,mid,i,j);
    int p2 = query(right,mid+1,j,i,j);

    return p1 + p2;
}
int main()
{
    ar[1] = 0;
    ar[2] = 0;
    ar[3] = 0;
    int n = 3;
    build(1,1,n);
    //cout<<tree[4];
    update(1,1,n,3,1);
    cout<<query(1,1,3,1,3)<<endl;

    cout<<query(1,1,n,2,3)<<endl;
}
