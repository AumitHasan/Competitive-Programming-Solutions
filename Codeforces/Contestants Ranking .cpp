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

string str[103][4],ch,ah="Ahmad";
int n,ar[103][4];

map<string,int>mp;
vector<string>v[105];

void solve()
{
    mp.clear();
    mem(v,0);
    //

    mp[ah] = 1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>ch;
            str[i][j] = ch;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(str[i][j]==ah){
                for(int k=1;k<=3;k++){
                    if(str[i][k]==ah) continue;
                    mp[str[i][k]] = 2;
                }
            }
        }
    }
    for(int pos=2;pos<=100;pos++){

        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                //
                if(mp[str[i][j]]==pos){
                    for(int k=1;k<=3;k++){
                        if(mp[str[i][k]]) continue;
                        mp[str[i][k]] = pos+1;
                    }
                }
            }
        }
    }
    int last = 0,c=0;
    for(map<string,int>:: iterator it = mp.begin(); it != mp.end(); ++it){
        //cout<<it->first<<" "<<it->second<<endl;
        v[it->second].push_back(it->first);
        last = max(last,it->second);
        c++;
    }
    //cout<<last<<endl;
    for(int i=0;i<=last;i++){
        sort(v[i].begin(),v[i].end());
    }
    cout<<c<<endl;
    for(int i=1;i<=last;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" "<<i-1<<endl;
        }
    }
    for(int i=0;i<v[0].size();i++) cout<<v[0][i]<<" undefined"<<endl;
}
int main()
{
    IO;

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
