#include<bits/stdc++.h>

using namespace std;

bool flag[100000];

int main()
{
    int x,k,div,a,b;
    cin>>x>>k;
    while(k--){
        cin>>div;
        if(div==1){
            cin>>a>>b;
            flag[a] = flag[b] = true;
        }
        else{
            cin>>a;
            flag[a] = 1;
        }
    }
    set<int>st;
    for(int i=1;i<x;i++){
        if(!flag[i]) st.insert(i);
    }
    int mn=0,mx = st.size();
    while(st.size()>0){
        int tmp = *st.begin(); st.erase(tmp);
        mn++;
        if(st.size()>0 && tmp+1 == *st.begin()) st.erase(tmp+1);
    }
    cout<<mn<<" "<<mx<<endl;
}
