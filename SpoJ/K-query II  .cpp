#include<bits/stdc++.h>
using namespace std;

#define mx 10007

int tree[174][10007],ar[30007];
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
    int idx = 10006;
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
//
void SQD_update(int bk,int ix,int val)
{
    int idx = ar[ix];
    ar[ix] = val;

    while(idx<mx){
        tree[bk][idx]--;
        idx += idx & (-idx);
    }
    idx = val;
    while(idx<mx){
        tree[bk][idx]++;
        idx += idx & (-idx);
    }
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
        scanf("%d",&type);
        if(type){ // 1
            scanf("%d%d%d",&l,&r,&v);
            printf("%d\n",SQD_query(l-1,r-1,v));
        }
        else{ // 0
            scanf("%d%d",&ix,&v);
            int bk = (ix-1) / blk_sz;
            SQD_update(bk,ix-1,v);
        }
    }
    return 0;
}
