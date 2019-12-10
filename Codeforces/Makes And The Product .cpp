#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int

ll nc3(ll a)
{
    return a * (a-1) * (a-2) / 6;
}
ll nc2(ll a)
{
    return a * (a-1) / 2;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        mp[ar[i]]++;
    }
    sort(ar,ar+n);
    //cout<<mp[2]<<endl;
    //cout<<(100000*9999*9998)/6<<endl;
    if(mp[ar[0]]>=3) cout<<nc3(mp[ar[0]])<<endl;
    else if(mp[ar[0]]==2) cout<<mp[ar[2]]<<endl;
    else if(mp[ar[1]]>1) cout<<nc2(mp[ar[1]])<<endl;
    else if(mp[ar[0]]==1 && mp[ar[1]]==1) cout<<mp[ar[2]]<<endl;
    else cout<<1<<endl;

    return 0;
}
