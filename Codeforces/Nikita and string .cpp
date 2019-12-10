#include<bits/stdc++.h>
using namespace std;

int ar[1000000],mx[100000];

int main()
{
    string str;
    cin>>str;


    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='a') ar[i] = 1;
        mx[i] = ar[i] + mx[i+1];
    }


    int a=0,res=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'){
            a++;
            res = max(res, a + mx[i+1]);
            int b = 0;
            for(int j=i+1;j<str.length();j++){
                if(str[j]=='b'){
                    b++;
                    res = max(res, a+b+mx[j]);
                }
            }
        }
    }
    int b = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='b'){
            b++;
            //cout<<mx[i]<<endl;
            res = max(res,b+mx[i]);
        }
    }
    cout<<res<<endl;
}
