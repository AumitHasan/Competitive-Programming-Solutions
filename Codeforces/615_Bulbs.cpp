#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m,bulb,x,i;

    cin>>n>>m;
    int b[m+1];

     for(i=0;i<=m;i++)
        b[i]=0;
    while(n--)
    {
        scanf("%d",&bulb);
        while(bulb--){
            scanf("%d",&x);
            b[x]++;
        }
    }

    for(i=1;i<=m;i++)
        if(b[i]==0){
            cout<<"NO"<<endl;
            return 0;
        }


        cout<<"YES"<<endl;


return 0;
}
