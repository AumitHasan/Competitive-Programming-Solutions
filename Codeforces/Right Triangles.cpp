#include<bits/stdc++.h>
using namespace std;

char ch[1003][1003];
int row[1003],col[1003];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long rt=0;
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //scanf("%c",&ch[i][j]);
            cin>>ch[i][j];
            if(ch[i][j]=='*'){row[i]++; col[j]++;}
        }
    }
    //cout<<row[1]<<" "<<row[2]<<" "<<row[3]<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
                //cout<<row[i]<<" "<<col[j]<<endl;
            if(ch[i][j]=='*'){
                rt += (row[i]-1)*(col[j]-1);
            }
        }
    }
    cout<<rt<<endl;

    return 0;
}
