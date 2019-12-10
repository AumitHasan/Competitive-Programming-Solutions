#include<bits/stdc++.h>
using namespace std;
#define mx 100003

int ar[mx],n,Q,num;

int bin(int lo,int hi)
{
    if(lo>hi) return -1;

    int mid = (lo+hi)/2;

    if(ar[mid]==num){
        if(lo==hi) return mid;
        bin(lo,mid);
    }
    else if(ar[mid]>num) bin(lo,mid-1);
    else bin(mid+1,hi);
}
int main()
{
    scanf("%d %d",&n ,&Q);
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    for(int i=0;i<Q;i++){
        scanf("%d",&num);
        int res = bin(0,n-1);
        printf("%d\n",res);
    }
    return 0;
}
