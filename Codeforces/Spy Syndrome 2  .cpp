#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define umap unordered_map
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define IO ios::sync_with_stdio(false)
#define base 53

ll ar[10007],dp[10007];
umap<llu,string>mp;
vector<string>v;

void print(int pos)
{
    if(pos==0) return;
    print(pos - mp[dp[pos]].length());
    v.push_back(mp[dp[pos]]);
}
int main()
{
    IO;

    int n,m;
    string str,ch;
    cin>>n;
    cin>>str;
    reverse(str.begin(),str.end());
    ar[0] = str[0];
    for(int i=1;i<n;i++){
        ar[i] = (ar[i-1] * base) + str[i];
    }
    //
    llu len,hv;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>ch;
        len = ch.length();
        hv = 0;
        for(int j=0;j<len;j++){
            hv = (hv * base) + tolower(ch[j]);
        }
        mp[hv] = ch;
    }
    mem(dp,-1);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        hv = 0;
        if(dp[i] != -1){
            for(int j=i;j<n;j++){
                hv = hv * base + str[j];
                if(mp.count(hv)) dp[j+1] = hv;
            }
        }
    }
    print(n);
    for(int i=v.size()-1;i>=0;i--){
        if(i>0) cout<<v[i]<<" ";
        else cout<<v[i]<<endl;
    }
    return 0;
}
