#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)
#define mx 200007

int res[200007];
int s,e,n,k,q,x;

struct info{
    int pos, neg;
}ar[200007];

ll tree[mx*3];

void initial(int node,int i,int j)
{
    if(i==j){
        if(res[i]>=k) tree[node] = 1;
        else tree[node]   = 0;
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (i+j)/2;

    initial(left,i,mid);
    initial(right,mid+1,j);

    tree[node] = tree[left]+tree[right];
}
ll query(int node,int i,int j,int qs,int qe)
{

    if(qs>j || qe<i) return 0;
    if(i>=qs&&j<=qe){
        return tree[node];
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (i+j)/2;

    ll p1 = query(left,i,mid,qs,qe);
    ll p2 = query(right,mid+1,j,qs,qe);

    return p1+p2;
}
int main()
{
    IO;

    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        ar[s].pos++;
        ar[e].neg += -1;
    }
    int c =0;
    for(int i=0;i<=200000;i++){
        c += ar[i].pos;
        res[i] = c;
        c += ar[i].neg;
    }
    initial(1,1,200007);
    //for(int i=90;i<=100;i++) cout<<res[i]<<" ";
    //cout<<endl;
    while(q--){
        cin>>s>>e;
        cout<<query(1,1,mx,s,e)<<endl;
        //cout<<x<<endl;
    }
}
