#include<bits/stdc++.h>
using namespace std;

#define MAX 100007

int ar[MAX],l[MAX],r[MAX],x;

int main()
{
    int n,k,mn,mx;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
        //mx = (i==0) ? ar[i] : max(mx,ar[i]);
        if(i==0){
            mx = ar[i];
            mn = ar[i];
        }
        else{
            mx = max(ar[i],mx);
            mn = min(ar[i],mn);
        }
        //mn = (i==0) ? ar[i] : min(mn,ar[i]);
    }

    if(k==1) cout<<mn<<endl;
    else if(n<=2 || k>2) cout<<mx<<endl;
    else{
        x = ar[0];
        for(int i=0;i<n;i++){
            x = min(x,ar[i]);
            l[i] = x;
        }
        x = ar[n-1];
        for(int i=n-1;i>=0;i--){
            x = min(x,ar[i]);
            r[i] = x;
        }
        int ans = -1e9;
        for(int i=0;i<n-1;i++){
            x = max(l[i],r[i+1]);
            ans = max(ans,x);
        }
        cout<<ans<<endl;
    }
}
