#include<bits/stdc++.h>

using namespace std;

int n,ar[100007],g[100007];

void solve()
{
    int in = n;
    bool f=true,bc=true;
    for(int i=0;i<n;i++){
        if(ar[i]>g[i]) f = false;
        if(ar[i]>g[--in]) bc = false;
    }
    if(!f && !bc) cout<<"none"<<endl;
    else if(f && bc) cout<<"both"<<endl;
    else if(f) cout<<"front"<<endl;
    else cout<<"back"<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        for(int i=0;i<n;i++) scanf("%d",&g[i]);
        solve();
    }
    return 0;
}
