#include<bits/stdc++.h>

using namespace std;

int num[11];

int main()
{
    string str;
    int n,m=0;
    cin>>n>>str;
    if(n==0 && str[0]=='0' && str.length()==1){
        cout<<"OK"<<endl;
        return 0;
    }

    int tmp = n;
    while(tmp>0){
        num[tmp%10]++; tmp/=10;
    }
    //
    int ans = 0;
    for(int i=1;i<10;i++){
        if(num[i]){
            ans = (ans*10) + i;
            num[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        if(num[i]){
            while(num[i]){
                ans = (ans*10) + i;
                num[i]--;
            }
        }
    }
    string ch = "";
    while(ans>0){
        ch += (ans%10) + '0';
        ans /= 10;
    }
    reverse(ch.begin(),ch.end());
    //cout<<m<<" "<<ans<<endl;
    if(str[0]=='0' || ch != str) cout<<"WRONG_ANSWER"<<endl;
    else cout<<"OK"<<endl;

    return 0;
}
