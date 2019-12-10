#include<bits/stdc++.h>
using namespace std;
int num(int i,int dig);

long long dp[5009][28],sz;
string str;

long long call(int i,int al)
{
    if(al>26 or str[i]=='0') return 0;
    if(i>=sz) return 1;
    if(dp[i][al] != -1) return dp[i][al];

    long long p1=0,p2=0;

    if(i+1<=sz)
        p1 = call(i+1,num(i,1));

    if(i+2<=sz)
        p2 = call(i+2,num(i,2) );

    return dp[i][al] = p1+p2;

}
int num(int i,int dig)
{
    int val=0;
    for(int j=i;j<i+dig;j++) val = (val*10)+(str[j]-'0');
    //cout<<val<<endl;
    return val;
}
int main()
{
    while(1){
        cin>>str;
        if(str.size()==1 and str[0]=='0') break;

        memset(dp,-1,sizeof(dp));
        sz = str.length();

        long long res = call(0,0);

        printf("%lld\n",res);
    }
    return 0;
}
