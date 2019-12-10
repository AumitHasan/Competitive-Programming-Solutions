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

#define mx 1e18

int n,pos,prime[100],as,bs;
ll pre[100][65],A[26128],B[206128];
vector<ll>vec;
set<ll>st;

void call(int i,ll val,int last,int flag)
{
    //cout<<i<<endl;
    if(i>=last){
        st.insert(val);
        //if(flag) B[++bs] = val;
        //else A[++as] = val;
        return;
    }

    if(mx/val >= prime[i]) call(i,val*prime[i],last,flag);
    call(i+1,val,last,flag);

}
void pree()
{
    for(int i=0;i<n;i++){
        pre[i][0] = 1;
        ll val = 1;
        for(int j=1;j<64;j++){
            if(mx/prime[i] >= val){
                val *= prime[i];
                pre[i][j] = val;
            }
            else break;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&prime[i]);
    scanf("%d",&pos);
    //sort(prime,prime+n);
    int lo=0,hi=n-1;
    while(lo<=hi){
        //swap(prime[lo],prime[hi]);
        lo++; hi--;
    }
    //
    pree();
    //
    call(0,1,n/2,0);
    cout<<st.size()<<" ";
    st.clear();
    //call(n/2,1,n,1);
    cout<<st.size()<<endl;
    cout<<as<<" "<<bs<<endl;
    for(int i=0;i<10;i++) cout<<A[i]<<" "<<B[i]<<endl;

}
