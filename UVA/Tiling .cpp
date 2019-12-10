#include<bits/stdc++.h>
using namespace std;



#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

string str[259];

string add(string a, string b){
    string ret;
    int la = a.size(),lb = b.size();

    for(int i = 0,c = 0;i < la || i < lb || c > 0;++i){
        if(i < la) c += a[i] - '0';
        if(i < lb) c += b[i] - '0';
        ret += '0' + c % 10;
        c /= 10;
    }
    return ret;
}
int main()
{

    str[0] = "1";
    str[1] = "1";
    str[2] = "3";
    string A,B,res;
    for(int i=3;i<=250;i++){
        res = "0";
        res = add(res,str[i-1]);
        res = add(res,str[i-2]);
        res = add(res,str[i-2]);
        str[i] = res;
    }
    for(int i=1;i<=250;i++){
        reverse(str[i].begin(),str[i].end());
    }

    int n;
    while(~scanf("%d",&n)){
        cout<<str[n]<<endl;
    }
    return 0;
}
