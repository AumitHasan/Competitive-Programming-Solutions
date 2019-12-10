#include<bits/stdc++.h>
using namespace std;

int main(){

    long test,k,m,len,i,j,value;
    cin>>test;
    while(test--){

        cin>>k;
        char a[k];
        long b[k];

        for(i=0;i<k;i++)
         {   cin>>a[i];
             cin>>b[i];
         }

        cin>>m;
        char str[10000];
        value=len=0;
        gets(str);
        while(m--){

            gets(str);
            len=strlen(str);

            for(i=0;i<k;i++){

                for(j=0;j<len;j++)
                {
                    if(a[i]==str[j])
                        value += b[i];
                }

            }


        }

        double x = (double) value/100;
        printf("%.2lf$\n",x);


    }


return 0;
}
