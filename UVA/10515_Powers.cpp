#include<bits/stdc++.h>
using namespace std;

int two[]={6,2,4,8};
int three[]={1,3,9,7};
int four[]={6,4,6,4};
int seven[]={1,7,9,3};
int e8[]={6,8,4,2};
int nine[]={1,9,1,9};


int main()
{
    while(1)
    {
        string s,str;
        cin>>s>>str;

        if(s=="0"&&str=="0") break;

        if(str=="0"){
           cout<<"1"<<endl;
           continue;
        }

        int a,b=0;
        a = s[s.length()-1]-'0';
        int l = str[str.length()-1]-'0';

        if(a==0){
            cout<<"0"<<endl;
            continue;
        }


        for(int i=0;i<str.length();i++) b =((b*10)+str[i]-'0')%4;
        cout<<"B : "<<b<<endl;
        if(b==1 || b==5 || b==6||b==0){
            cout<<l<<endl;
            continue;
        }
        //if(b==0) cout<<"1"<<endl;
        if(b==2) cout<<two[b]<<endl;
        else if(b==3) cout<<three[b]<<endl;
        else if(b==4) cout<<four[b]<<endl;
        else if(b==7) cout<<seven[b]<<endl;
        else if(b==8) cout<<e8[b]<<endl;
        else if(b==9) cout<<nine[b]<<endl;

    }

return 0;
}
