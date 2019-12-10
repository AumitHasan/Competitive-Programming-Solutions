#include<bits/stdc++.h>
using namespace std;

#define mx 100001

int ar[100007];

struct st{
    int a,b;
}tree[mx*3];

void initial(int node,int i,int j)
{
    if(i==j){
        tree[node].a = ar[i];
        tree[node].b = ar[i];
        return ;
    }

    int left = node*2;
    int right = node*2 + 1; //left + 1
    int mid = (i+j)/2;

    initial(left,i,mid);
    initial(right,mid+1,j);

    tree[node].a = min(tree[left].a,tree[right].a);
    tree[node].b = max(tree[left].b,tree[right].b);
}

int query_min(int node,int i,int j,int qs,int qe)
{
    if(qs>j || qe<i){
        return 1e9;
    }
    if(i>=qs && j<=qe){
        return tree[node].a;
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (i+j)/2;

    int p1 = query_min(left,i,mid,qs,qe);
    int p2 = query_min(right,mid+1,j,qs,qe);

    return min(p1,p2);
}

int query_max(int node,int i,int j,int qs,int qe)
{
    if(qs>j || qe<i){
        return -1e9;
    }
    if(i>=qs && j<=qe){
        return tree[node].b;
    }

    int left = node*2;
    int right = node*2 + 1;
    int mid = (i+j)/2;

    int p1 = query_max(left,i,mid,qs,qe);
    int p2 = query_max(right,mid+1,j,qs,qe);

    return max(p1,p2);
}
int main()
{


    int T,N=0,x;
    scanf("%d",&T);
    while(++N<=T){
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&ar[i]);
        }

        initial(1,1,n);
        //cout<<tree[4].a<<" "<<tree[4].b<<endl;
        int dif = 0;
        for(int i=1;i<=n-d+1;i++){
            int mn = query_min(1,1,n,i,i+d-1);
            int mxx = query_max(1,1,n,i,i+d-1);

            if(dif<mxx-mn) dif = mxx - mn;
        }

        printf("Case %d: %d\n",N,dif);

    }

return 0;
}
