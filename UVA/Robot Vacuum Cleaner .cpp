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

int n,sum[mx];

struct info{
    int s,h;
    bool operator<(const info& nw) const
    {
        if(h == nw.h) return s>nw.s;
        return h < nw.h;
    }
}ar[mx];

int main()
{

    ll ans = 0;

    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        int c = 0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='s') c++;
            else ans += c;
        }
        ar[i].s = c;
        ar[i].h = str.length() - c;
    }
    //cout<<ans<<endl;
    sort(ar,ar+n);
    //
    for(int i=n-1;i>=0;i--){
        sum[i] = sum[i+1] + ar[i].h;
    }
    for(int i=0;i<n;i++){
        ans += (ar[i].s * sum[i+1]);
    }
    cout<<ans<<endl;
}

