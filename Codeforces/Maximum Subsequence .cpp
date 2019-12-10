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

#define mx 100007

int ar[40],A[262244],B[262244];
int n,ans,m,asz,bsz,add,ck;
set<int>st;

void src(int num)
{
    add = 0;
    int mid,lo=1,hi=bsz;
    while(lo<=hi){
        mid = (lo+hi)/2;
        if(B[mid]>=num) hi = mid-1;
        else{
            add = B[mid];
            //cout<<add<<endl;
            lo = mid + 1;
        }
    }
}
void solve()
{
    //cout<<"F"<<endl;
//    for(int i=1;i<=asz;i++) cout<<A[i]<<" ";
//    cout<<endl;
//    for(int i=1;i<=bsz;i++) cout<<B[i]<<" ";
//    cout<<endl;

    int val;
    for(int i=1;i<=asz;i++){

        val = m - A[i];
        src(val);
        ans = max(ans,(A[i]+add)%m);
    }
    //
    cout<<ans<<endl;
}
void call(int i,int val,int last)
{
    if(i>last){
        st.insert(val%m);
        return;
    }
    call(i+1,(val+ar[i])%m,last);
    call(i+1,val%m,last);
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
    //
    if(n==1){
        cout<<ar[1]%m<<endl;
        return 0;
    }
    //
    asz=bsz=0;

    call(1,0,n/2);
    //cout<<st.size()<<endl;

    while(!st.empty()){
        A[++asz] = *st.begin();
        ans = max(ans,A[asz]%m);
        st.erase(*st.begin());
    }
    //
    call(n/2 + 1,0,n);
    //cout<<st.size()<<endl;

    while(!st.empty()){
        B[++bsz] = *st.begin();
        ck = max(ck,B[bsz]%m);
        st.erase(*st.begin());
    }
    //cout<<ans<<endl;

    ans = max(ck,ans);
    //
    //cout<<"Fc"<<endl;
    solve();
    //
    return 0;
}

