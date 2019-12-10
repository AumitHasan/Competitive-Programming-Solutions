#include<bits/stdc++.h>
using namespace std;

int ar[200007];
unordered_map<int,int>mp,ck;

int main()
{
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    for(int i=0;i<n;i++){
        if(i==0){
            c++;
            ck[ar[0]] = 1;
            continue;
        }
        if(ck[ar[i]]==0){
            c++;
            ck[ar[i]] = c;
        }
    }
    cout<<c<<endl;
}
