#include<bits/stdc++.h>

using namespace std;

int num,in;
int a[123456],tail[123456],id[123456],parent[123456];

int call(int last){
    if(parent[last]!=-1)call(parent[last]);
    printf("%d\n",a[last]);
}
int bin(int lo,int hi,int key)
{
    while(hi>lo){
        int mid = (lo+hi)/2;
        if(tail[mid]>=key) hi = mid;
        else lo = mid+1;
    }
    return hi;
}
void LIS()
{
    int len=0;
    tail[0] = a[0];
    parent[0] = -1;
    id[0] = 0;
    for(int i=1;i<=in;i++){
        //int pos = lower_bound(tail,tail+len,S[i])-tail;
        if(a[i]<tail[0]){
            tail[0] = a[i];
            parent[i] = -1;
            id[0] = i;
        }
        else if(a[i]>tail[len]){
            tail[++len] = a[i];
            parent[i] = id[len-1];
            id[len] = i;

        }
        else{
            int ix = bin(0,len,a[i]);
            tail[ix] = a[i];
            parent[i] = id[ix-1];
            id[ix] = i;

        }
    }

    call(id[len]);
}
/*
int call(int last){
    if(par[last]!=-1)call(parent[last]);
    printf("%d\n",a[last]);
}
void LIS(){
    int last=0,len=0;
    for(int i=0;i<=in;i++){
        int pos=lower_bound(tail,tail+len,a[i])-tail;
        tail[pos]=a[i];
        id[pos]=i;
        par[i] = pos>0 ? id[pos-1]:-1;
        if(pos==len){
            len++;
            last=i;
        }
        else if(pos+1==len)last=i;
    }
    printf("%d\n-\n",len);
    call(last);
}
*/
int main()
{
    in=-1;
    for(int i=0;i<8;i++){ cin>>num; a[++in]=num;}
    LIS();

    return 0;
}
