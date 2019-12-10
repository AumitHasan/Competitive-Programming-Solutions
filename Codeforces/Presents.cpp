#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,c,h;
    int day[366]={0};
    cin>>n>>k;
    cin>>c;
    int p=0;
    for(int i=0;i<c;i++){
        scanf("%d",&h);
        day[h]=1;
    }
    c=0;
    for(int i=1;i<=n;i++){
        c++;
        if(day[i]==1){
            p++;
            c=0;
        }
        else if(k==c){
            p++;
            c=0;
        }

    }
    cout<<p<<endl;
}
