#include<bits/stdc++.h>
using namespace std;

string str;

int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        //if(str.length())
        bool flag = false;
        for(int i=0;i<8;i++){
            if(i==4){
                if(str[i]<'A' || str[i]>'Z') flag = true;
            }
            else{
                if(str[i]<'1' || str[i]>'9') flag = true;
            }
        }
        if(flag) continue;
        //
        //cout<<str<<endl;
        if(str[0]==str[1]) cout<<str<<endl;
//        else if(str[2]==str[3]) cout<<str<<endl;
//        else if(str[5]==str[6] || str[6]==str[7]) cout<<str<<endl;N

    }
    return 0;
}
