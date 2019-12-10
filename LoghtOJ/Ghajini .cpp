#include<bits/stdc++.h>
using namespace std;

int ar[100005];
multiset<int>st;

int main()
{

    int T,N=0,x;
    scanf("%d",&T);
    while(++N<=T){
        st.clear();
        int n,d;
        scanf("%d %d",&n,&d);
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
        }
        int in=-1,dif=0;
        for(int i=0;i<d;i++){
            st.insert(ar[i]);
            //cout<<ar[i]<<endl;
        }



        if(dif<*st.rbegin() - *st.begin()) dif = *st.rbegin() - *st.begin();
        //cout<<dif<<endl;
        st.erase(ar[++in]);
        for(int i=d;i<n;i++){
            st.insert(ar[i]);
            if(dif<*st.rbegin() - *st.begin()) dif = *st.rbegin() - *st.begin();
            st.erase(ar[++in]);
        }
        printf("Case %d: %d\n",N,dif);
    }
    return 0;
}
