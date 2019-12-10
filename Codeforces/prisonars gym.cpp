#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,x,p,cnt=0,c=0;
    cin>>n>>t>>x;
    vector<int>v;
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        if(p>t){
            v.push_back(c);
            c=0;
        }
        else c++;
    }
    if(c>0) v.push_back(c);
    c = x-1;
    int tem,res = 0;
    for(int i=0;i<v.size();i++){
        tem = v[i]-c;
        if(tem>0) res += tem;
    }
    cout<<res<<endl;

    return 0;
}
