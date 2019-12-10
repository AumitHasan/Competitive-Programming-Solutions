#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

int main()
{
    string str;
    cin>>str;
    ll len = str.length();
    string ch;
    ch.push_back(str[len-1]);
    ll n=0,s;
    for(ll i=0;i<len-1;i++) n = (n*10)+(str[i]-48);
    //cout<<n<<" "<<ch<<endl;
    if(ch=="f") s=1;
    else if(ch=="e") s=2;
    else if(ch=="d") s=3;
    else if(ch=="a") s=4;
    else if(ch=="b") s=5;
    else if(ch=="c") s=6;

        ll a,res=0,x,y,z;
        a=n/2;
        if(n%2!=0) a++;
        x=a/2;
        if(a%2==0){
            res = (x-1)*12;
            res += (n-3)+s;
            if(n%2==0) res+=6;
        }
        else{
            res = x*12;
            res += (n-1)+s;
            if(n%2==0) res+=6;
        }
        cout<<res<<endl;

return 0;
}

