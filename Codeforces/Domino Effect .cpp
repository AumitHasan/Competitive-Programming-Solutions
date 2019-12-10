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

#define mx 100007

int a[3007],b[3008];

int main()
{
    mem(a,-1); mem(b,-1);
    int n,c=0,f=0,ans=0;
    string str;
    cin>>n>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='R') f = 1,a[i]=1;
        else if(str[i]=='L') f = 0;
        else{
            if(f) a[i] = a[i-1] + 1;
        }
    }
    f = 0;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='L') f = 1,b[i]=1;
        else if(str[i]=='R') f = 0;
        else{
            if(f) b[i] = b[i+1] + 1;
        }
    }
//    for(int i=0;i<n;i++) cout<<a[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<n;i++) cout<<b[i]<<" ";
//    cout<<endl;
    //cout<<ans<<endl;
    for(int i=0;i<str.size();i++){
        if(a[i]<0 && b[i]<0){
            ans++;
            //cout<<ans;
        }
        else if(a[i]==b[i] && a[i]>0){
            ans++;
            //cout<<ans<<endl;
        }
    }


    cout<<ans<<endl;
}
