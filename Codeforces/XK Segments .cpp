#include<bits/stdc++.h>
using namespace std;

#define mx 100007

int a,b,n,k,x,s,ar[mx];
long long int res,f;

int right_src(int lo,int hi)
{
    int ans = -1,a;
    while(lo<=hi){
        int mid = (lo+hi) / 2;
        a = ar[mid]/x;
        if(a-s == k){
            ans = mid;
            hi = mid-1;
        }
        else if(a-s < k) lo = mid+1;
        else hi = mid - 1;
    }
    return ans;
}
int right_s(int lo,int hi)
{
    int ans = -1,a;
    while(lo<=hi){
        int mid = (lo+hi) / 2;
        a = ar[mid]/x;
        if(a-s == k){
            ans = mid;
            lo = mid+1;
        }
        else if(a-s < k) lo = mid+1;
        else hi = mid - 1;
    }
    return ans;
}
int left_s(int lo,int hi,int val)
{
    int ans = -1,a;
    while(lo<=hi){
        int mid = (lo+hi) / 2;

        if(ar[mid]==val){
            ans = mid;
            hi = mid-1;
        }
        else if(ar[mid]<val) lo = mid+1;
    }
    return ans;
}
int main()
{
    scanf("%d %d %d", &n, &x, &k);
    for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
    sort(ar,ar+n+1);

    for(int i=1;i<=n;i++){
        s = ar[i]/x;
        if(ar[i]%x==0) s--;
        b = right_src(i,n);
        if(b>0){
            int in = b;
            b = right_s(in,n);
            //cout<<"r: "<<in<<" "<<b<<endl;
            if(b>0){
                int tmp = left_s(1,i-1,ar[i]);

                if(k==1 && ar[i]%x==0 && tmp>0) res += i-tmp;
                if(k==0 && ar[i]%x!=0 && tmp>0) res += i-tmp;
                //
                res += b-in+1;
            }
            else res++;
        }

        //if(i==1) continue;


    }
    cout<<res<<endl;
}
