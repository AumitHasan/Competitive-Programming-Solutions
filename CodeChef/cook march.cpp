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

int n,m,mat[107][107];

int main()
{
    IO;
    //
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<107;i++)
            for(int j=0;j<107;j++) mat[i][j]=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mat[i][j];
                if(mat[i][j]==-1){
                    mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
                    //cout<<i<<" "<<j<<" "<<mat[i][j-1]<<endl;
                    //if(i==n) cout<<"("<<mat[i][j-1]<<" "<<mat[i-1][j]<<") "<<endl;
                }
            }
            //cout<<endl;
        }
        //cout<<endl;
        //
        bool flag = false;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i][j] < mat[i][j-1]){
                    //cout<<i<<" "<<j<<endl;
                    flag = true;
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                    //cout<<j<<" "<<i<<endl;
                if(mat[j][i] < mat[j-1][i]) flag = true;
            }
        }
        if(flag) cout<<-1<<endl;
        else{
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<mat[i][j];
                    if(j<m) cout<<" ";
                    else cout<<endl;
                }
            }
        }
    }
}
