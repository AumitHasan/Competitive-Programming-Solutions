#include<bits/stdc++.h>
using namespace std;

#define mx 1000007

int ar[mx],cnt[mx];

int main()
{
    cout<<(0^)
    string str;
    cin>>str;

    int len = str.length();
    //cout<<len<<endl;
    for(int i=0;i<=len-5;i++){
        if(str[i]=='m' && str[i+1]=='e' && str[i+2]=='t' && str[i+3]=='a' && str[i+4]=='l'){
            ar[i] = 1;
            //i+=4;
            //cout<<i<<endl;
        }
    }
    for(int i=len-1;i>=0;i--){
        cnt[i] = ar[i] + cnt[i+1];
        //cout<<cnt[i]<<" ";
    }
    long long int c=0;
    for(int i=0;i<=len-5;i++){
        if(str[i]=='h' && str[i+1]=='e' && str[i+2]=='a' && str[i+3]=='v' && str[i+4]=='y'){
            c += cnt[i+1];
            //i+=4;
            //cout<<i<<endl;
        }
    }
    cout<<c<<endl;
}
