#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000

int ar[1007],n,cont,mx;

int bin(int s,int e)
{
    if(n<=cont){
        int r = 0;
        for(int i=0;i<n;i++){
            if(ar[i]>r) r = ar[i];
        }
        return r;
    }
    int lo=1,hi=INF+9,mid=0,val=0,res=0,c;

    while(lo<hi){
        mid = (lo+hi)/2;

        val=res=c=0;
        for(int i=0;i<n;i++){
            if(mid<mx){
                c=cont+6;
                break;
            }
            if(val+ar[i]>mid){
                c++;
                if(res<val) res = val;
                //cout<<lo<<" "<<mid<<" "<<hi<<" "<<res<<endl;
                val = ar[i];
            }
            else{
                //if(ar[i]<mid) c
                val += ar[i];
            }
        }
        if(val>0) c++;
        //cout<<lo<<" "<<mid<<" "<<hi<<endl;
        //cout<<"C: "<<c<<endl;
        if(c<=cont) hi = mid;
        //else if(c==cont) hi = mid;
        if(c>cont) lo = mid+1;

        //cout<<lo<<" "<<hi<<endl<<endl;
        //getchar();
    }
    return lo;
}
int main()
{
    int T,N=0;
    cin>>T;
    while(++N<=T){
        scanf("%d %d",&n ,&cont);
        mx = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
            if(mx<ar[i]) mx = ar[i];
        }

        int res = bin(0,n-1);

        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
