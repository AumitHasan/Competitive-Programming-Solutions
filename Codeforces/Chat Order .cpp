#include<bits/stdc++.h>
using namespace std;

#define M 2000000

unordered_map<string,int>mp;
vector<string>v;

int main()
{
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        v.push_back(s);
    }
    while(!v.empty()){
        s = v.back();
        v.pop_back();
        if(mp[s]==0){
            cout<<s<<endl;
            mp[s]=1;
        }
    }

    return 0;
}
