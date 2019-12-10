#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[26],i,j,n,m,c=0;

    cin>>n>>m;

    for(i=0;i<25;i++)
        a[i]=0;

    char s[n][m];

    for(i=0;i<n;i++){

        for(j=0;j<m;j++)
            cin>>s[i][j];

    }

    for(i=0;i<n-1;i++){

        for(j=0;j<m-1;j++)
        {
            a[s[i][j]-'a']=1;
            a[s[i][j+1]-'a']=1;
            a[s[i+1][j]-'a']=1;
            a[s[i+1][j+1]-'a']=1;

            if(a[0] and a[2] and a[4] and a[5])
                c++;

            a[0]=a[2]=a[4]=a[5]=0;
        }

    }

    cout<<c<<endl;


return 0;
}
