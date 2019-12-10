#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mx 100005

int n,q;
int c,i,j;

struct info{
    int s,p,c;
}tree[mx*4];

void update(int node,int a,int b,int i,int j)
{
    if(tree[node].c==1) //pre
    {
        //cout<<"z";
        tree[node].s = (b-a+1)-tree[node].s;
        if(a!=b){
            tree[node*2].c = 1;
            tree[node*2+1].c = 1;
        }
        tree[node].c = 0;
    }
    else if(tree[node].p==1) // pre
    {   //cout<<"x";
        if(tree[node].s>0&&tree[node].s<(b-a+1))
            tree[node].s = (b-a+1)-tree[node].s;
        //else if(tree[node].s==(b-a+1)) tree[node].s = 0;
        else tree[node].s = b-a+1;
        //tree[node].s = (b-a+1)-tree[node].s;
        if(a!=b){
            tree[node*2].p = 1;
            tree[node*2+1].p = 1;
        }
        tree[node].p = 0;
    }
    else if(tree[node].p==2) //pre
    {
        //cout<<"y";
        if(tree[node].s>0&&tree[node].s<(b-a+1))
            tree[node].s = (b-a+1)-tree[node].s;
        else if(tree[node].s == 0) tree[node].s = b-a+1;
        else tree[node].s = 0;

        if(a!=b){
            tree[node*2].p = 2;
            tree[node*2+1].p = 2;
        }
        tree[node].p = 0;
    }


    if(i>b || j<a) return ;

    if(a>=i&&b<=j) // within range
    {
        //cout<<"a";
        if(tree[node].s == 0)
        {
            tree[node].s = b-a+1;
            if(a!=b){
                tree[node*2].p = 1;
                tree[node*2+1].p = 1;
            }
            tree[node].p = 0;
        }
        else if(tree[node].s == (b-a+1))
        {
            tree[node].s = 0;
            if(a!=b){
                tree[node*2].p = 2;
                tree[node*2+1].p = 2;
            }
            tree[node].p = 0;
        }
        else if(tree[node].s>0&&tree[node].s<(b-a+1))
        {
            tree[node].s = (b-a+1)-tree[node].s;
            if(a!=b){
                tree[node*2].c = 1;
                tree[node*2+1].c = 1;
            }
            tree[node].c = 0;
        }

        return;
    }//within range

    int mid = (a+b)/2;
    int left = node*2;
    int right = left+1;

    update(left,a,mid,i,j);
    update(right,mid+1,b,i,j);

    tree[node].s = tree[left].s + tree[right].s;
}
int query(int node,int a,int b,int i,int j)
{
    if(i>b || j<a) return 0;

    if(tree[node].c==1) //pre
    {
        tree[node].s = (b-a+1)-tree[node].s;
        if(a!=b){
            tree[node*2].c = 1;
            tree[node*2+1].c = 1;
        }
        tree[node].c = 0;
    }
    if(tree[node].p==1) // pre
    {
        if(tree[node].s>0&&tree[node].s<(b-a+1))
            tree[node].s = (b-a+1)-tree[node].s;
        else tree[node].s = b-a+1;
        //tree[node].s = (b-a+1)-tree[node].s;
        if(a!=b){
            tree[node*2].p = 1;
            tree[node*2+1].p = 1;
        }
        tree[node].p = 0;
    }
    if(tree[node].p==2) //pre
    {
        //if(tree[node].s>0&&tree[node].s<(b-a+1))
          //  tree[node].s = (b-a+1)-tree[node].s;
        tree[node].s = 0;

        if(a!=b){
            tree[node*2].p = 2;
            tree[node*2+1].p = 2;
        }
        tree[node].p = 0;
    }


    if(a>=i&&b<=j) // within range
    {
        return tree[node].s;
    }//within range

    int mid = (a+b)/2;
    int left = node*2;
    int right = left+1;

    ll q1 = query(left,a,mid,i,j);
    ll q2 = query(right,mid+1,b,i,j);

    return q1+q2;
}
int main()
{
    memset(tree,0,sizeof(tree));
    cin>>n>>q;
    for(int k=0;k<q;k++)
    {
        c=i=j=0;
        cin>>c>>i>>j;

        if(c==0) update(1,1,n,i,j);
        else if(c==1) cout<<query(1,1,n,i,j)<<endl;
        cout<<endl;
        for(int i=1;i<20;i++) cout<<tree[i].p<<" ";
        cout<<endl;
        for(int i=1;i<20;i++) cout<<tree[i].c<<" ";
        cout<<endl;
        for(int i=1;i<20;i++) cout<<tree[i].s<<" ";
        cout<<endl<<endl;
    }

return 0;
}

