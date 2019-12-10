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

int ar[200][200],ans[105][105],r[200],c[200],x[105],y[105];
vector<int>rv[200],cv[200];


int main()
{
    int n,m;
    string str;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int j=0;j<m;j++){
            if(str[j]=='#') ar[i][j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        if(!r[i]){
            //cout<<i<<endl;
            mem(y,0);
            r[i] = 1;
            int cnt=0;
            for(int j=0;j<m;j++){
                if(ar[i][j]){
                    y[j] = 1; cnt++;
                }
            }
            //cout<<cnt<<endl;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int tmp = 0,tt=0;
                for(int k=0;k<m;k++){
                    if(ar[j][k]==1) tmp++;
                    if(ar[j][k]==1 && y[k]) tt++;
                }

                //cout<<j<<" "<<cnt<<" "<<tmp<<" "<<tt<<endl;
                if(tt){
                    if((tmp != cnt) || (tt != tmp) ){cout<<"No"<<endl; return 0;}
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}
