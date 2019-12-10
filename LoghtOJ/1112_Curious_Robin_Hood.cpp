#include<bits/stdc++.h>
using namespace std;

#define mx 100001
#define ll long long

int  arr[mx];
int  tree[mx*3];

void initial(int node,int i,int j)
{
    if(i==j){
        tree[node]=arr[i];
        return ;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (i+j)/2;

    initial(left,i,mid);
    initial(right,mid+1,j);

    tree[node] = tree[left]+tree[right];
}

void update(int node,int i,int j,int indx,int value,int v)
{
    if(i==j&&i==indx){
        tree[node]=value+v;
        arr[indx]=value+v;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (i+j)/2;

    if(indx<=mid) update(left,i,mid,indx,value,v);
    if(indx>mid) update(right,mid+1,j,indx,value,v);

    tree[node] = tree[left]+tree[right];
}

int query(int node,int i,int j,int qs,int qe)
{
    if(i>qe || j<qs) return 0;
    if(i>=qs&&j<=qe) return tree[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (i+j)/2;

    int p1 = query(left,i,mid,qs,qe);
    int p2 = query(right,mid+1,j,qs,qe);

    return p1+p2;
}

int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {

        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        initial(1,0,n-1);

         printf("Case %d:\n",N);
        while(q--){

            int x;
            scanf("%d",&x);
            if(x==1)
            {
                int a;
                scanf("%d",&a);
                printf("%d\n",arr[a]);
                update(1,0,n-1,a,0,0);
            }
            else if(x==2)
            {

                int a,v;
                scanf("%d%d",&a,&v);
                update(1,0,n-1,a,v,arr[a]);

            }
            else if(x==3)
            {

                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,0,n-1,a,b));
            }
        }
    }

return 0;
}

