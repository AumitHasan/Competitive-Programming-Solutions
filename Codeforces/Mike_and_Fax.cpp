#include<bits/stdc++.h>
using namespace std;
int main(){

    int i,j,m=1,x,y,p=0,c=1,k,len;
    char s[1001];

    cin>>s>>k;

    len=strlen(s);
    p=len/k;

    if(len%k != 0){

         cout<<"NO"<<endl;
         return 0;
    }

    //cout<<len<<" "<<p<<endl;

    for(i=0;m<=k;i+=p){

        x=y=0;
        x=p+i-1;
        y=x;
          //  cout<<i<<" "<<x<<endl;
        for(j=i;j<x;j++)
        {
            if(s[j] != s[y])
                break;
            y--;
        }

        if(s[j]!= s[y])
        {
            c=0;
            break;
        }
     m++;
    }


    if(c==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

return 0;
}
