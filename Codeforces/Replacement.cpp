#include<iostream>
using namespace std;
#include<string.h>

int main(){

    int m,n,i,c=0,cnt=0,x;
    cin>>n>>m;
    char a[n],y;
    cin>>a;

    for(i=0;i<n;i++)
    {
            if(a[i]=='.')
            {
                c++;
                if(c==2)
                    cnt++;
            }
            if(c==2)
                c=1;
            if(a[i] != '.')
                c=0;
    }

    x=y=0;
    while(m--){

        cin>>x>>y;


        if(y == '.')
        {
            if(a[x-1]!='.'){

                if(a[x-2]=='.')
                    cnt++;

                if(a[x]=='.' )
                    cnt++;
            }
            a[x-1]=y;

        }
        else{
            if(a[x-1]=='.'){
                if(a[x-2]=='.' && (x-2)>=0)
                    cnt--;
                if(a[x]=='.' && x<n)
                    cnt--;
            }
            a[x-1]=y;

        }

        cout<<cnt<<endl;

    }


return 0;
}
