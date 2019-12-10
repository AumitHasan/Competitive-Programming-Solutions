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

llu mx = 1e18;

llu n,pos,ar[20],num[20][65];
//llu ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
set<llu>st;

void pre()
{
    for(int i=1;i<=n;i++){
        llu val = ar[i];
        int in = 0;
        while(val<=mx){
            num[i][++in] = val;
            val *= ar[i];
        }
    }
}
void call(int i,llu val,int last)
{
    if(i>last){
        st.insert(val);
        return ;
    }

    if(val*ar[i]<=mx) call(i,val*ar[i],last);
    call(i+1,val,last);

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ar[i];
    sort(ar,ar+n+1);
    cin>>pos;
    //
    int in = n;
    for(int i=1;;i++){
        swap(ar[i],ar[in]);
        in--;
        if(in<i) break;
    }
    //
    call(1,1,n/2);
    //cout<<st.size()<<endl;
    //return 0;
    in=0;
    while(!st.empty()){
        cout<<*st.begin()<<" ";
        st.erase(*st.begin());
        in++;
        if(in>5) break;
    }
    cout<<endl;
    //
    call(n/2 + 1,1,n);
    while(!st.empty()){
        cout<<*st.begin()<<" ";
        st.erase(*st.begin());
        in++;
        if(in>11) break;
    }
    cout<<endl;

}
