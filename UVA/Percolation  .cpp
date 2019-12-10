#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,1};
int dy[]={-1,1,0};
#define IO ios::sync_with_stdio(false)
#define mem(a,b) memset(a,b,sizeof(a))

int ar[1007][1007];

int main()
{
    IO;

    string str;
    int n,m;
    for(int i=0;i<1007;i++){
        for(int j=0;j<1007;j++) ar[i][j]=2;
    }

    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>str;
            for(int j=0;j<m;j++){
                if(str[j]=='1'){
                    ar[i][j+1] = 1;
                }
                else ar[i][j+1] = 0;
            }
        }
        for(int i=1;i<=m;i++){
            if(ar[1][i]==0) ar[1][i]=2;
        }
//        cout<<endl;
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=m;j++) cout<<ar[i][j]<<" ";
//            cout<<endl;
//        }
        int x,y;

        for(int i=1;i<n;i++){

            for(int j=1;j<=m;j++){
                if(ar[i][j]==2){
                    for(int k=0;k<3;k++){
                        x = i+dx[k];
                        y = j+dy[k];
                        if(x>0 && x<=n && y>0 && y<=m && ar[x][y]==0) ar[x][y]=2;
                     }
                }
            }
            for(int j=m;j>0;j--){
                if(ar[i][j]==2){
                    for(int k=0;k<3;k++){
                        x = i+dx[k];
                        y = j+dy[k];
                        if(x>0 && x<=n && y>0 && y<=m && ar[x][y]==0) ar[x][y]=2;
                     }
                }
            }
        }
        bool flag = false;
        for(int i=1;i<=m;i++){
            if(ar[n][i]==2) flag = true;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
//        cout<<endl;
//        for(int i=0;i<=n;i++){
//            for(int j=0;j<=m;j++) cout<<ar[i][j]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
