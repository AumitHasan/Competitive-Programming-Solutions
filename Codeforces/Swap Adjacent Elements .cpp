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

#define mx 200007

umap<int,int>mp;
int ar[mx],A[mx],flag[mx];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        ar[i] = A[i];
    }
    sort(ar,ar+n+1);
    for(int i=1;i<=n;i++){
        mp[ar[i]] = i;
    }
    for(int i=1;i<=n;i++){
        A[i] = mp[A[i]];
        //cout<<A[i]<<" ";
    }
    string str;
    cin>>str;
    for(int i=1;i<n;i++){
        flag[i] = str[i-1] - '0';
        //cout<<flag[i]<<" ";
    }
    flag[n] = 0;
    //
    int pre,mn=1e9,val = 0,ck=0,f=0;
    for(int i=1;i<=n;i++){
        val = max(val,A[i]);
        mn = min(mn,A[i]);
        if(flag[i]==0){
                //cout<<val<<" "<<i<<endl;
            if(f && mn<=pre) ck = true;

            if(val > i) ck = true;
            val = 0;
            mn = 1e9;
            f = 1;
            pre = i;
        }
    }
    if(ck) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
