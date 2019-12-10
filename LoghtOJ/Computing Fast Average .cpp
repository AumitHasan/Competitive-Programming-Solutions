#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100007

////



int n,ar[mx];
struct info{
    int prop,sum;
}tree[mx * 3];


void update(int node,int i,int j,int qs,int qe,int value)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){ // This node needs to be updated
        tree[node].sum = (j - i + 1) * tree[node].prop; // Update

        if(i != j){
            tree[left].prop = tree[node].prop;
            tree[right].prop = tree[node].prop;
        }

        tree[node].prop = 0; // reset
    }

    if(qs>j || qe<i) return;

    if(i>=qs && j<=qe){ // in range
        tree[node].sum = (j - i + 1) * value;

        if(i != j){
            tree[left].prop = value;
            tree[right].prop = value;
        }
        return;
    }


    update(left,i,mid,qs,qe,value);
    update(right,mid+1,j,qs,qe,value);

    tree[node].sum = (j - i + 1)*tree[left].prop + (j - i + 1)*tree[right].prop;
}
int query(int node,int i,int j,int qs,int qe,int carry)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    if(tree[node].prop != 0){  // This node needs to be updated
        tree[node].sum = (j - i + 1) * tree[node].prop; // update

        if(i != j){
            tree[left].prop = tree[node].prop;
            tree[right].prop = tree[node].prop;
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
    int type,a,b,q,val,T,N=0;
    sci(T);
    while(++N<=T){
        scii(n,q);
        while(q--){
            sci(type);
            if(type==1){
                sciii(a,b,val);
                a++; b++;
                update(1,1,n,a,b,val);
            }
            else{

            }
        }
    }
}
