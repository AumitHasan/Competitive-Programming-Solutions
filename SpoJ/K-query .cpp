#include<bits/stdc++.h>
using namespace std;

#define mx 1000000007

unordered_map<int,unordered_map<int,int> > tree;

int ar[30007];
int blk_sz,n;

void BIT_build(int bk,int idx)
{
    while(idx<mx){
        tree[bk][idx]++;
        idx += idx & (-idx);
    }
}
//
void build()
{
    blk_sz = sqrt(n) * 3;
    int blk_num = -1;

    for(int i=0;i<n;i++){
        if(i%blk_sz==0) blk_num ++;
        BIT_build(blk_num,ar[i]);
    }
}
//
int BIT_query(int bk,int val)
{
    int idx = mx;
    int a=0,b=0;

    while(idx>0){
        a += tree[bk][idx];
        idx -= idx & (-idx);
    }
    idx = val;
    while(idx>0){
        b += tree[bk][idx];
        idx -= idx & (-idx);
    }
    return a - b;
}
//
int SQD_query(int l,int r,int val)
{
    int cnt=0;

    while(l%blk_sz!=0 && l<=r){
        if(ar[l]>val) cnt++;
        l++;
    }

    while(l + blk_sz - 1 <= r){
        int blk_num = l / blk_sz;

        cnt += BIT_query(blk_num,val);
        l += blk_sz;
    }
    while(l<=r){
        if(ar[l]>val) cnt++;
        l++;
    }
    return cnt;
}
//
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);
    build();

    int q,type,l,r,v,ix;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&l,&r,&v);
        printf("%d\n",SQD_query(l-1,r-1,v));
    }
    return 0;
}
