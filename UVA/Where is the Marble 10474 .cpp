#include<bits/stdc++.h>
using namespace std;

int ar[10009],num;

int src(int lo,int hi)
{
    int pos = 0;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(ar[mid]==num){
            pos = mid;
            hi = mid-1;
        }
        if(ar[mid]<num) lo = mid+1;
        else if(ar[mid]>num) hi = mid-1;
    }
    return pos;
}
int main()
{
    int n,q,T=0;
    while(scanf("%d%d",&n,&q) && n && q){
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        sort(ar,ar+n+1);
        printf("CASE# %d:\n",++T);
        for(int i=0;i<q;i++){
            scanf("%d",&num);
            int res = src(1,n);
            if(!res) printf("%d not found\n",num);
            else printf("%d found at %d\n",num,res);
        }
    }
    return 0;
}
