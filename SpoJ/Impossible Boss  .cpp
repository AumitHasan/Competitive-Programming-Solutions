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
int n,q;

struct info{
    ll sum,cnt,fs;
}tree[mx*3];


ll clc_sum(ll s,ll dif,int i,int j)
{

    ll cnt = j - i + 1;
    ll e = s + (cnt-1)*dif;
    //cout<<"f: "<<s<<" "<<dif<<" "<<i<<" "<<j<<" "<<(cnt * (s + e)) / 2<<endl;
    return (cnt * (s + e)) / 2;
}
ll query(int node,int i,int j,int s,int e)
{
    int mid = (i + j) / 2;
    int left = 2 * node;
    int right = left + 1;

    if(tree[node].cnt || tree[node].fs){
        tree[node].sum += clc_sum(tree[node].fs,tree[node].cnt,i,j);
        if(i!=j){
            tree[left].fs += tree[node].fs;
            tree[left].cnt += tree[node].cnt;

            tree[right].fs += tree[node].fs + ((i+j)/2 + 1 - i)*tree[node].cnt;
            tree[right].cnt += tree[node].cnt;
        }
        tree[node].fs = tree[node].cnt = 0;
    }

    if(i>e || j<s) return 0;
    if(i>=s && j<=e){
        return tree[node].sum;
    }
    ll a = query(left,i,mid,s,e);
    ll b = query(right,mid+1,j,s,e);

    //tree[node].sum = tree[left].sum + tree[right].sum;
    return a + b;
}
void update(int node,int i,int j,int s,int e,int suru)
{
    int mid = (i + j) / 2;
    int left = 2 * node;
    int right = left + 1;

    if(tree[node].cnt || tree[node].fs){
        //cout<<"up"<<endl;
        tree[node].sum += clc_sum(tree[node].fs,tree[node].cnt,i,j);
        //cout<<tree[node].sum<<endl;

        if(i!=j){
            tree[left].fs += tree[node].fs;
            tree[left].cnt += tree[node].cnt;

            tree[right].fs += tree[node].fs + ((i+j)/2 + 1 - i)*tree[node].cnt;
            tree[right].cnt += tree[node].cnt;
        }
        tree[node].fs = tree[node].cnt = 0;
    }

    if(i>e || j<s) return;
    if(i>=s && j<=e){
        tree[node].fs += i - suru + 1;
        tree[node].cnt += 1;

        tree[node].sum += clc_sum(tree[node].fs,tree[node].cnt,i,j);

        if(i!=j){
            tree[left].fs += tree[node].fs;
            tree[left].cnt += tree[node].cnt;

            tree[right].fs += tree[node].fs + ((i+j)/2 + 1 - i)*tree[node].cnt;
            tree[right].cnt += tree[node].cnt;
        }
        tree[node].fs = tree[node].cnt = 0;
        return;
    }
    update(left,i,mid,s,e,suru);
    update(right,mid+1,j,s,e,suru);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
int main()
{

    int type,s,e;
    ll ans;

    scii(n,q);
    while(q--){
        sciii(type,s,e);
        if(type){
            ans = query(1,1,n,s,e);
            printf("%lld\n",ans);
        }
        else{
            update(1,1,n,s,e,s);
            //cout<<tree[1].sum<<" "<<tree[2].sum<<" "<<tree[3].sum<<endl;
            //cout<<tree[1].sum<<" "<<tree[2].fs<<" "<<tree[3].fs<<endl;
        }
    }
    return 0;
}
