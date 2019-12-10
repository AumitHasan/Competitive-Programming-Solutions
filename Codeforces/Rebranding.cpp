#include<bits/stdc++.h>
using namespace std;

int main(){

    long i=0,m,n,j,a[26],c,d;
    char x[1],y[1];

    cin>>n>>m;
    char s[n];

    cin>>s;

    for(j=0;j<26;j++)
          a[j]=j;




    while(m--){

        cin>>x[0]>>y[0];

        c = x[0] - 'a';
        d = y[0] - 'a';

        for(i=0;i<26;i++)
        {
            if(a[i] == c)
                a[i] = d;

            else if(a[i] == d)
                a[i] = c;

        }

    }

    for(i=0;i<n;i++){

        int value = s[i] - 'a';
        printf("%c",a[value]+'a');

    }

    cout<<endl;



return 0;
}
