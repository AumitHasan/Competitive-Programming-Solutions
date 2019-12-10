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


#define     mx                      20000007

////

int n,q,boss[30007],set_id[30007],sub[30007],tree[mx*3],tmp[mx*3];

struct info{
    int id,salary,tall;
    bool operator<(const info& nw) const
    {
        if(tall == nw.tall) return salary < nw.salary;
        return tall < nw.tall;
    }
}ar[30007];

map<int,int>mp;

void query_clr(int node,int i,int j)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(i>j || !tree[node]) return;
    if(i==j){
        tmp[node] = tree[node] = 0;
        return;
    }

    query_clr(left,i,mid);
    query_clr(right,mid+1,j);

    //tree[node] = MAX3(tree[node],tree[left],tree[right]);
    tree[node] = (tree[left] | tree[right]);
}
void query(int node,int i,int j,int s,int e,int id)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(s>j || e<i || !tree[node]) return;
    if(i==j){
        //cout<<"p: "<<tmp[node]<<" "<<id<<endl;
        sub[id] += sub[tmp[node]] + 1;
        boss[tmp[node]] = id;
        tmp[node] = tree[node] = 0;
        return;
    }

    query(left,i,mid,s,e,id);
    query(right,mid+1,j,s,e,id);

    //tree[node] = MAX3(tree[node],tree[left],tree[right]);
    tree[node] = (tree[left] | tree[right]);
}
void update(int node,int i,int j,int idx,int id)
{
    int mid = (i + j) / 2;
    int left = node * 2;
    int right = left + 1;

    if(i>idx || j<idx || i>j) return;
    if(i>=idx && j<=idx){
        tmp[node] = id;
        //cout<<"y: "<<i<<" "<<tmp[node]<<endl;
        tree[node] = 1;
        return;
    }

    update(left,i,mid,idx,id);
    update(right,mid+1,j,idx,id);

    //tree[node] = MAX3(tree[node],tree[left],tree[right]);
    tree[node] = (tree[left] | tree[right]);
}
void clr()
{
    for(int i=0;i<30007;i++){
        boss[i] = sub[i] = set_id[i] = 0;
    }
}
int main()
{
    int t,num,x;
    sci(t);
    while(t--){
        mp.clear();
        clr();
        //
        scii(n,q);
        for(int i=0;i<n;i++){
            sciii(ar[i].id,ar[i].salary,ar[i].tall);
            mp[ar[i].id] = i;
            set_id[i] = ar[i].id;
            ar[i].id = i;
        }
        sort(ar,ar+n);
//        cout<<endl;
//        for(int i=0;i<n;i++) cout<<ar[i].id<<" "<<ar[i].salary<<" "<<ar[i].tall<<endl;
//        cout<<endl;
        for(int i=0;i<n;i++){
            query(1,1,mx-1,1,ar[i].salary-1,ar[i].id);
            update(1,1,mx-1,ar[i].salary,ar[i].id);
            //cout<<tree[1]<<endl;
            //break;
        }
        query_clr(1,1,mx-1);
        //cout<<endl;
        for(int i=0;i<n;i++){
            //cout<<ar[i].id<<" "<<ar[i].salary<<" "<<ar[i].tall<<endl;
            //cout<<set_id[ar[i].id]<<" "<<boss[ar[i].id]<<" "<<sub[ar[i].id]<<endl;
            if(boss[ar[i].id]==0) boss[ar[i].id] = 0;
            else boss[ar[i].id] = set_id[boss[ar[i].id]];
        }
        while(q--){
            sci(num);
            x = mp[num];
            printf("%d %d\n",boss[x],sub[x]);
        }
    }
    return 0;
}
