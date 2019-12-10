#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,c=0,cl=0,cr=0,cnt=0,a,b,total=0;
    cin>>n>>m;
    string s[n];
    int row[n],col[m];
    for(int i=0;i<n;i++){
        c=0;
        cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]=='*') c++;
        }
        row[i]=c;
        total+=c;

    }
    //cout<<total<<endl;
    if(total==0){
        cout<<"YES"<<endl;
        cout<<"1 1"<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        c=0;
        for(int j=0;j<n;j++){
            if(s[j][i]=='*') c++;
        }
        col[i]=c;
    }

    int sum,x,y;
    c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a=row[i];
            b=col[j];
            sum = a+b;
            if(s[i][j]=='*') sum--;
            //cout<<"sum: "<<sum<<endl;
            if(total-sum==0){
                x=i;
                y=j;
                c=1;
                break;
            }
        }
        if(c==1) break;
    }
    if(c==0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<x+1<<" "<<y+1<<endl;
    }



    return 0;
}
