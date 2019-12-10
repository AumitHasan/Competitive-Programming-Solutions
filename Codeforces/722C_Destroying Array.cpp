#include<bits/stdc++.h>
using namespace std;
#define mx 100003
#define ll long long int

multiset<ll>mval;
set<int>st;
set<int>::iterator it;
ll sum[mx],ar[mx],lo,hi,p,n;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll x,y,z,num;
    //scanf("%i64d",&n);
    cin>>n;
    for(ll i=1;i<=n;i++){
        //scanf("%i64d",&num);
        cin>>num;
        if(i>1) sum[i] = sum[i-1]+num;
        else sum[i]=num;
    }

    sum[0]=0;
    sum[n+1]=sum[n];
    st.insert(0);
    st.insert(n+1);
    mval.insert(sum[n]);
    for(ll i=0;i<n;i++){
        //scanf("%i64d",&p);
        cin>>p;
        it = st.lower_bound(p);
        hi=*it;
        *it--;
        lo=*it;
        x = sum[p-1]-sum[lo];
        y = sum[hi-1]-sum[p];
        z = sum[hi-1]-sum[lo];
        //cout<<lo<<" "<<p<<" "<<hi<<endl;
        mval.erase(mval.find(z));
        mval.insert(x);
        mval.insert(y);
        //printf("%I64d\n",*mval.rbegin());
        cout<<*mval.rbegin()<<endl;
        st.insert(p);
    }
    return 0;
}
