#include<bits/stdc++.h>
using namespace std;

int ar[1005]={0};
vector<int>v;

int main()
{
    int n,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ar[x]++;
    }

    for(int i=0;i<=1003;i++){
        if(ar[i]>0) v.push_back(ar[i]);
    }

    sort(v.begin(),v.end());

    if(v.size()==1){

        if(v[0]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(v.size()==2){
        if(abs(v[0]-v[1])==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        for(int i=0;i<=v.size()-2;i++)
        {
            if(i<v.size()-2) c+=v[i];
            int f=v[i];
            for(int j=i;j<v.size();j++) v[j]-=f;
        }

        if(v[v.size()-1]<=c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
