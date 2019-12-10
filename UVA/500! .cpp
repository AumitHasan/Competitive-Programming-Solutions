#include<bits/stdc++.h>
using namespace std;

string fact[1001];

string to_str(int n)
{
    stringstream s;
    s << n;
    string str = s.str();
    return str;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string s="1",ch;
    fact[0] = "1";
    fact[1] = s;
    //cout<<fact[1];
    for(int i=2;i<=1000;i++){
        s = "";
        int len = fact[i-1].length();
        int carry=0,val=0;
        for(int j=len-1;j>=0;j--){
            val = i * (fact[i-1][j]-'0') + carry;
            s += to_str(val%10);
            carry = val/10;
        }
        if(carry>9){
            ch = "";
            ch = to_str(carry);
            reverse(ch.begin(),ch.end());
            s += ch;
        }
        else if(carry>0) s += to_str(carry);
        reverse(s.begin(),s.end());
        fact[i] = s;
        //cout<<i<<" "<<fact[i]<<endl;
        //if(i==10) break;
    }
    //cout<<fact[1000].length();
    //return 0;
    int n;
    while(~scanf("%d!",&n)){
        printf("%d!\n",n);
        cout<<fact[n]<<endl;
    }
}
