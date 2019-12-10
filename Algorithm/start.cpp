#include<bits/stdc++.h>
using namespace std;

int used[40],number[40];
long long int c;

void prmt(int att,int n)
{
    if(att>6){
        //for(int i=1;i<=5;i++) printf("%d ",number[i]);
        //printf("\n");
        //getchar();
        c++;
        return ;
    }
    //cout<<att<<endl;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=1;
            number[att]=i;
            prmt(att+1,n);
            used[i]=0;
        }
    }
}
int main()
{
    prmt(1,8);
    cout<<c<<endl;
}
