#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    char x[1000001],y[1000001];

    scanf("%s %s",&x,&y);

    while(x[a]=='0')   a++;
    while(y[b]=='0')   b++;

    int i = strlen(x) - a;
    int j = strlen(y) - b;

    //cout<<i<<" "<<j<<endl;

    if(i>j)
        cout<<">"<<endl;
    else if(i<j)
        cout<<"<"<<endl;
    else{



        for(int k=0;k<i;k++)
        {
            if(x[a]>y[b]){
                cout<<">"<<endl;
                return 0;
            }
            if(x[a]<y[b]){
                cout<<"<"<<endl;
                return 0;
            }
            a++;
            b++;
        }

        cout<<"="<<endl;
    }

return 0;
}
