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

ll a,b,x,y,k,A[4][4],B[4][4];
vector<pr>v,vec;
map<int,map<int,int> >alice,bob;
map<pr,int>mp;

int main()
{
    alice[2][1] = alice[1][3] = alice[3][2] = 1;
    bob[1][2] = bob[3][1] = bob[2][3] = 1;
    //
    cin>>k>>x>>y;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++) cin>>A[i][j];
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++) cin>>B[i][j];
    }

    int aa = alice[x][y];
    int bb = bob[x][y];

    //cout<<endl;
    v.push_back(pr(x,y));

    for(int i=1;i<=2000;i++){
        int e = A[x][y];
        int f = B[x][y];
        v.push_back(pr(e,f));
        x = e;
        y = f;
        //if(i<20) cout<<e<<" "<<f<<endl;
    }
    //cout<<a<<" "<<b<<endl;
    //for(int i=0;i<8;i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    x=y=0;
    if(k>1){
        for(int i=0;;i++){
            pr nw = v[i];
            if(mp[nw]==0) mp[nw] = i;
            else{
                for(int j=0;j<mp[nw];j++){
                    a += alice[v[j].first][v[j].second];
                    b += bob[v[j].first][v[j].second];
                }
                //cout<<mp[nw]<<" "<<a<<" "<<b<<endl;

                k -= mp[nw];
                x=y=0;
                for(int j=mp[nw];j<i;j++){
                    vec.push_back(v[j]);
                    x += alice[v[j].first][v[j].second];
                    y += bob[v[j].first][v[j].second];
                }
                int sz = vec.size();
                x = x * (k/sz);
                y = y * (k/sz);
                //cout<<x<<" "<<y<<endl;
                int rem = k % sz;
                //cout<<k<<" "<<sz<<endl;
                for(int j=0;j<rem;j++){
                    x += alice[vec[j].first][vec[j].second];
                    y += bob[vec[j].first][vec[j].second];
                }
                break;
            }

        }
    }
    else{
        a = aa; b = bb;
    }

    //ans:
    cout<<a+x<<" "<<b+y<<endl;
}
