#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 150007

int n,len,k,M,cnt,pos,ar[mx],tree[3*mx];

void build(int node,int i,int j)
{
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(i==j){
        tree[node] = (ar[i]) ? 1 : 0;
        return ;
    }

    build(left,i,mid);
    build(right,mid+1,j);

    tree[node] = tree[left] + tree[right];
}
void update(int node,int i,int j,int idx,int num,int task)
{
    //cout<<node<<" "<<i<<" "<<j<<" "<<idx<<endl;
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(idx>j || idx<i) return ;
    if(idx==i && idx==j){
        if(task){
            tree[node] = 1;
            //cout<<"a: "<<node<<endl;
        }
        else{
            tree[node] = ar[i] = 0;
        }
        return;
    }

    update(left,i,mid,idx,num,task);
    update(right,mid+1,j,idx,num,task);

    tree[node] = tree[left] + tree[right];
}
void query(int node,int i,int j)
{
    //cout<<node<<" "<<i<<" "<<j<<" "<<cur<<" "<<kth<<endl;
    int left = node * 2;
    int right = left + 1;
    int mid = (i+j) / 2;

    if(i>k) return;

    if(mid < k){
        cnt += tree[left];
        query(right,mid+1,j);
    }
    else if(mid==k){
        cnt += tree[left];
        return;
    }
    else if(mid > k){
        query(left,i,mid);
        query(right,mid+1,j);
    }
}
int idx_src(int kth)
{
    int lo = 1, hi = len,ans;
    while(lo<=hi){
        cnt = 0;
        int mid = (lo+hi) / 2;
        k = mid;
        query(1,1,len);
        //cout<<k<<" "<<cnt<<endl;
        //getchar();
        if(cnt>kth){
            hi = mid - 1;
        }
        else if(cnt==kth){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{

    int T,N=0,q,p;
    char ch;
    scanf("%d",&T);
    while(++N<=T){
        mem(ar,0);
        mem(tree,0); // refresh
        //
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        //
        len = n + q + 2;
        build(1,1,len);
        //cout<<tree[1]<<endl;
        //
        printf("Case %d:\n",N);
        while(q--){
            //cout<<tree[1]<<endl;
            cin>>ch;
            if(ch=='c'){
                int kk;
                scanf("%d",&kk);
                //
                pos = 0;
                if(tree[1]<kk) printf("none\n");
                else{
                    //cout<<"f"<<endl;
                    pos = idx_src(kk);
                    printf("%d\n",ar[pos]);
                }

                //cout<<"for: "<<tree[12]<<endl;
                //
                update(1,1,len,pos,0,0);
            }
            else{ // add solder last
                scanf("%d",&p);
                //cout<<"fuck n "<<n<<" "<<p<<endl;
                n++;
                update(1,1,len,n,p,1);
                //cout<<tree[24]<<endl;
                ar[n] = p;
            }
            //cout<<tree[7]<<" "<<val[6]<<endl;
        }
    }
    return 0;
}
