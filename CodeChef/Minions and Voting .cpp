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

#define mx 1000007

int n,ar[mx],vote[mx],ed[mx],st[mx];
ll val[mx];


void bin(int lo,int hi,int root)
{
    int mid,ans=0;
    while(lo<=hi){
        mid = (lo+hi) / 2;
        if(val[mid-1]-val[root] <= ar[root]){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid - 1;
    }
    if(ans){
        ed[ans]++;
        st[root] += (ans - root);
    }
}
void fnd(int lo,int hi,int root)
{
    int mid,ans=0;
    while(lo<=hi){
        mid = (lo+hi) / 2;
        if(val[mid+1]-val[root] <= ar[root]){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if(ans){
        ed[ans]++;
        st[root] += (root - ans);
    }
}
void left()
{
    val[0] = 0;
    for(int i=1;i<=n;i++) val[i] = val[i-1] + ar[i];
    //
    for(int i=1;i<n;i++){
        bin(i+1,n,i);
    }
//    for(int i=1;i<=n;i++) cout<<st[i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=n;i++) cout<<ed[i]<<" ";
//    cout<<endl;
    //
    ll sum = 0,m=0;
    for(int i=1;i<=n;i++){
        //cout<<sum<<" "<<m<<" ";
        if(sum>0){
            vote[i] += m;
            sum -= m;
        }
        if(st[i]){m++; sum+=st[i];}
        if(ed[i]) m -= ed[i];
        //cout<<sum<<" "<<m<<endl;
    }
//    for(int i=1;i<=n;i++) cout<<vote[i]<<" ";
//    cout<<endl;
}
void right()
{
    for(int i=0;i<n+5;i++) val[i] = ed[i] = st[i] = 0;
    ar[n+1] = ar[0] = 0;
    //
    for(int i=n;i>0;i--) val[i] = val[i+1] + ar[i];
    for(int i=n;i>1;i--){
        fnd(1,i-1,i);
    }
    //
//    for(int i=1;i<=n;i++) cout<<st[i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=n;i++) cout<<ed[i]<<" ";
//    cout<<endl;
    //
    ll sum=0,m=0;
    for(int i=n;i>=1;i--){
        if(sum>0){
            vote[i] += m;
            sum -= m;
        }
        if(st[i]){m++; sum+=st[i];}
        if(ed[i]) m -= ed[i];
    }
//    for(int i=1;i<=n;i++) cout<<vote[i]<<" ";
//    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n+4;i++) val[i] = st[i] = ed[i] = vote[i] = ar[i] = 0;
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        left();
        //cout<<endl;
        right();
        for(int i=1;i<=n;i++){
            printf("%d",vote[i]);
            if(i==n) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
