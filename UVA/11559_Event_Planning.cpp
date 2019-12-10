#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,b,h,w,c,mintk,seat,tk,i,p;

    while(scanf("%d %d %d %d",&n,&b,&h,&w)==4){

        int a[w];
        mintk=tk=c=0;
        while(h--){

            seat=0;
            cin>>p;
            for(i=0;i<w;i++)
            {
                cin>>a[i];
                seat+=a[i];
                if(a[i]>=n)
                    c=1;

            }

            if(c==0)
                continue;

            tk=p*n;
            if(tk>b)
                continue;


            if(tk<mintk || mintk==0)
                mintk=tk;

        }

        if(mintk==0)
            cout<<"stay home"<<endl;
        else
            cout<<mintk<<endl;

    }



return 0;
}
