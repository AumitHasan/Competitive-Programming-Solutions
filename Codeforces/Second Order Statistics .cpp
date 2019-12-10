#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int>st;
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        st.insert(a);
    }
    if(st.size()<2) cout<<"NO"<<endl;
    else{
            int x=0;
        for (set<int>::iterator it=st.begin(); it!=st.end(); ++it){
            x++;
            if(x==2){
                cout << *it<<endl;
                break;
            }
        }
    }
}
