#include<bits/stdc++.h>

using namespace std;

set<int>st;

int main()
{
    int t,n,tmp;
    cin>>t;
    while(t--){
        st.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&tmp); st.insert(tmp);
        }
        cout<<n-st.size()<<endl;
    }
    return 0;
}
