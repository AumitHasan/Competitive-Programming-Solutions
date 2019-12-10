#include<bits/stdc++.h>
using namespace std;

vector<char>vec;
string str;

int main()
{
    int T;
    cin>>T;
    while(T--){
        vec.clear();
        int n;
        cin>>n;
        cin>>str;
        for(int i=0;i<n;i++){
            if(vec.size()==0 || str[i]=='(') vec.push_back(str[i]);
            else{
                int len = vec.size();
                if(vec[len-1]=='(') vec.pop_back();
                else vec.push_back(str[i]);
            }
        }
        if(vec.size()==0) cout<<0<<endl;
        else{
            int c=0;
            for(int i=0;i<vec.size();i+=2){
                if(vec[i]==vec[i+1]) c++;
                else c+=2;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
