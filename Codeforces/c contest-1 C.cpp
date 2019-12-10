#include<bits/stdc++.h>
using namespace std;

#define mx 200007

int n,ar[mx],c;
unordered_map<int,int>mp,ck;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    for(int i=0;i<n;i++){
        if(mp[ar[i]]==0){
            c++;

            mp[i+1] = 1;
        }
        else{
            mp[ar[i]] = 0;
            mp[i+1] = 1;
        }
    }
    cout<<c<<endl;
}
