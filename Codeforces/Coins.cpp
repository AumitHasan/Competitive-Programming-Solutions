#include<bits/stdc++.h>
using namespace std;
int main(){

    char str[3];

    int i,a[3]={0,0,0},c=0,j;

    for(i=0;i<3;i++){

        cin>>str;

        if(str[1]=='>')
            a[str[0]-'A']++;
        else
            a[str[2]-'A']++;

    }

    for(i=0;i<3;i++){
        c=0;
        for(j=0;j<3;j++)
        {
            if(a[j]==i)
                c=1;

        }
        if(c==0)
            break;

    }

    if(c!=0)
    {

        for(i=0;i<3;i++)
        {

            for(j=0;j<3;j++)
            {
                if(a[j]==i)
                {
                    printf("%c",j+65);
                    break;
                }
            }
        }
        cout<<endl;

    }else
        cout<<"Impossible"<<endl;


return 0;
}
