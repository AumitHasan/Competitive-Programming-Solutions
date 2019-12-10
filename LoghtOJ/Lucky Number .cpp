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


#define     mx                      714717

////

int idx,ar[mx],lim,tree[mx*3],ans[mx];


void build(int node,int i,int j)
{
    int mid = (i+j) / 2;
    int left = 2*node;
    int right = left + 1;

    if(i>j) return;
    if(i==j){
        tree[node] = 1;
        return ;
    }
    build(left,i,mid);
    build(right,mid+1,j);

    tree[node] = tree[left] + tree[right];
}
void update(int node,int i,int j,int ix)
{
    int mid = (i+j) / 2;
    int left = 2*node;
    int right = left + 1;

    if(i>ix || j<ix) return;
    if(i>=ix && j<=ix){
        tree[node] = 0;
        return ;
    }
    update(left,i,mid,ix);
    update(right,mid+1,j,ix);

    tree[node] = tree[left] + tree[right];
}
int query(int node,int i,int j,int s,int e)
{
    int mid = (i+j) / 2;
    int left = 2*node;
    int right = left + 1;

    if(i>e || j<s) return 0;
    if(i>=s && j<=e) return tree[node];

    int a = query(left,i,mid,s,e);
    int b = query(right,mid+1,j,s,e);

    return a + b;
}
int src(int num,int lo,int hi)
{
//    int low = lo, high = hi;
//
//	while (low <= high)
//	{
//		int left_mid = low + (high - low) / 3;
//		int right_mid = high - (high - low) / 3;
//
//		int tmp = query(1,1,idx,1,left_mid);
//		int tmp2 = query(1,1,idx,1,right_mid);
//
//		if (tmp  == num)
//			return left_mid;
//
//		else if (tmp2 == num)
//			return right_mid;
//
//		else if (tmp  > num)
//			high = left_mid - 1;
//
//		else if (tmp2 < num)
//			low = right_mid + 1;
//
//		else
//			low = left_mid + 1, high = right_mid - 1;
//	}
//
//	return 0;

    int res=0,mid;
    int st = lo + 1;
    while(lo<=hi){
        mid = (lo + hi) / 2;
        if(query(1,1,idx,st,mid) >= num){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return res;
}
void solve()
{
    idx = 0;
    for(int i=1;i<1429434;i++){
        if(i&1) ar[++idx] = i;
    }
    lim = idx + 1;
    build(1,1,idx);
    //
    int s,tmp,last=2,c,inc,select_idx;
    for(int i=2;i<=100000;i++){
        s = src(i,1,idx);
        ans[i] = ar[s];
//        cout<<i-1<<" : "<<ar[s]<<endl;
//        getchar();

        last = s;
        inc = ar[s];
        c = 0;
        select_idx = 1;
        for(int j=inc;j<=idx;j+=inc){
            //tmp = min(select_idx*4, idx);
            if(tree[1] < j-c) break;
            tree[node] = 6;

            select_idx = src(inc,select_idx,idx);//min(idx,select_idx*5));
            //if(tmp> (idx+1)/2 ) tmp = idx;
            c++;
            update(1,1,idx,select_idx);
        }
    }
}
int main()
{
    solve();
    cout<<ans[100000]<<endl;
    return 0;
    int n,t,tc=0;
    sci(t);
    while(t--){
        sci(n);
        printf("Case %d: %d\n",++tc,ans[n]);
    }
    return 0;
}
