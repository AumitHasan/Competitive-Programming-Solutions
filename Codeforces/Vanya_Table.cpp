#include<bits/stdc++.h>
using namespace std;
int main(){

    int x1,x2,y1,y2,n,i,value=0;

    cin>>n;

    while(n--){

        x1=x2=y1=y2=0;

        cin>>x1>>y1>>x2>>y2;

        value+=(x2-x1+1)*(y2-y1+1);

    }

    cout<<value<<endl;

return 0;
}
