#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define mx 10001
#define bs 1000007

ll has[mx];
ll b[mx],com;

void pre_base()
{
    b[0]=1;
    for(int i=1;i<mx;i++)
    {
        b[i] = b[i-1]*bs;
    }
}
bool check(int i,int len)
{
    ll val;
    if(i==0) val = has[i+len-1];
    else val = has[i+len-1]-(has[i-1]*b[len]);

    //cout<<com<<" "<<val<<endl;
    if(com==val) return true;
    else return false;
}
int main()
{
    pre_base();

    string str,s;
    cin>>str>>s;

    ll len = str.length();
    ll len2 = s.length();

    has[0]=str[0];
    for(int i=1;i<len;i++) has[i] = (has[i-1]*bs)+str[i];

    com=0;
    for(int i=0;i<len2;i++) com = (com*bs)+s[i];

    //for(int i=0;i<len;i++) cout<<has[i]<<" ";
    //cout<<endl<<com;
    int c=0;
    for(int i=0;i<=len-len2;i++)
    {
        if(check(i,len2)==true) c++; //cout<<i<<endl;}
    }

    cout<<c<<endl;
    cout<<endl;

    //for(int i=0;i<len;i++) cout<<has[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<len;i++) cout<<b[i]<<" ";



return 0;
}
