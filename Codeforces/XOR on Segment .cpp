#include<stdio.h>
#include<bits/stdc++.h>

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef     long long int           ll;
typedef     unsigned long long int  llu;
typedef     pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)          scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     max3(a,b,c)             max(a,max(b,c))
#define     max4(a,b,c,d)           max(max(a,b),max(c,d))
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

int ar[mx],tmp[22],n,q;
ll pw[22];
ll clc;

struct info{
    ll sum;
    int flag,lazy,bit[22];
}tree[mx*3];


void binary(int node,int idx)
{
//    cout<<ar[idx]<<" "<<node<<" : ";
    int val=ar[idx],in = -1;
    while(val){
        tmp[++in] = val % 2;
        val /= 2;
    }
    idx = -1;
    for(int i=0;i<=in;i++){
        tree[node].bit[i] = tmp[i];
//        cout<<tree[node].bit[i]<<" ";
    }
//    cout<<endl;
}
ll clc_sum(int node,int lz,int cnt)
{
    mem(tmp,0);
    int in = -1;
    ll zero,one;
    while(lz){
        tmp[++in] = lz % 2;
        lz /= 2;
    }
    ll s = 0;
    for(int i=0;i<=21;i++){
        if(tmp[i]){
            if(tree[node].bit[i]==0) tree[node].bit[i] = cnt;
            else tree[node].bit[i] = cnt - tree[node].bit[i];
        }
        s += pw[i] * tree[node].bit[i];
    }
    return s;
}
void build(int node,int i,int j)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(i>j) return;
    if(i==j){
        binary(node,i);
        tree[node].sum = (ll) ar[i];
        return;
    }

    build(left,i,mid);
    build(right,mid+1,j);

    for(int i=0;i<=21;i++){
        tree[node].bit[i] = tree[left].bit[i] + tree[right].bit[i];
    }
    tree[node].sum = tree[left].sum + tree[right].sum;
}
ll query(int node,int i,int j,int s,int e)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(tree[node].lazy){
        tree[node].sum = clc_sum(node,tree[node].lazy,j-i+1);

        if(i != j){
            tree[left].lazy ^= tree[node].lazy;
            tree[right].lazy ^= tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if(i>e || j<s) return 0;
    if(i>=s && j<=e) return tree[node].sum;

    ll a = query(left,i,mid,s,e);
    ll b = query(right,mid+1,j,s,e);

    return a + b;
}
void update(int node,int i,int j,int s,int e,int val)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(tree[node].lazy){
        tree[node].sum = clc_sum(node,tree[node].lazy,j-i+1);

        if(i != j){
            tree[left].lazy ^= tree[node].lazy;
            tree[right].lazy ^= tree[node].lazy;
        }
        tree[node].lazy = 0;
    }

    if(i>j || i>e || j<s) return;
    if(i>=s && j<=e){
        tree[node].lazy ^= val;
//        cout<<i<<" x "<<j<<" "<<tree[node].lazy<<endl;
        tree[node].sum = clc_sum(node,tree[node].lazy,j-i+1);

        if(i != j){
            tree[left].lazy ^= tree[node].lazy;
            tree[right].lazy ^= tree[node].lazy;
        }
        tree[node].lazy = 0;
        return;
    }

    update(left,i,mid,s,e,val);
    update(right,mid+1,j,s,e,val);

    tree[node].sum = tree[left].sum + tree[right].sum;
    for(int i=0;i<=21;i++){
        tree[node].bit[i] = tree[left].bit[i] + tree[right].bit[i];
    }
    //tree[node].lazy = tree[left].lazy ^ tree[right].lazy;
}
void solve()
{
    pw[0] = 1;
    for(int i=1;i<=21;i++) pw[i] = pw[i-1] * 2;

}
void prnt()
{
    return;
    cout<<"prnt: "<<endl;
    for(int i=1;i<=25;i++){
        if(tree[i].sum <=0) continue;
        cout<<i<<" th node, "<<tree[i].sum<<" is sum, "<<tree[i].lazy<<" is lazy, "<<tree[i].flag<<" is flag, ";
        for(int j=0;j<7;j++) cout<<tree[i].bit[j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    solve();

    int type,l,r,x;

    sci(n);
    for(int i=1;i<=n;i++) sci(ar[i]);
    build(1,1,n);
//    cout<<endl;

    prnt();

    sci(q);
    while(q--){
        sci(type);
        if(type==1){ // query
            scii(l,r);
            printf("%lld\n",query(1,1,n,l,r));
//            cout<<"query "<<endl;
//            prnt();
        }
        else{ //XOR
            sciii(l,r,x);
            update(1,1,n,l,r,x);
//            cout<<"up "<<endl;
//            prnt();
            //cout<<"s: "<<tree[5].<<endl;
        }
    }
    return 0;
}
