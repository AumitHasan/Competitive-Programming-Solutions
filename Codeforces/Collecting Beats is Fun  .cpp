#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

map<int,int>mp;

int main()
{
    int n;
    cin>>n;
    string str[4];

    cin>>str[0]>>str[1]>>str[2]>>str[3];
    bool flag = false;

    for(int i=0;i<4;i++){
        //mp.clear();
        for(int j=0;j<4;j++){
            if(str[i][j] != '.') mp[str[i][j]-'0']++;
        }
    }
    for(int i=1;i<10;i++){
        if(mp[i]>2*n) flag = true;
    }

    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
