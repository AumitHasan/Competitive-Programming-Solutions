#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define sqrsize 320

int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474,
4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};

int ar[MAX],add_value[320];
int n,q,blk_sz,blk_num;
bool mark[10007];
int block[320][MAX];

void update(int l,int r,int val)
{
    blk_num = l/blk_sz;

    while(l<=r && l%blk_sz!=0){
        block[blk_num][ar[l]]--;

        ar[l] += val;
        block[blk_num][ar[l]]++;

        l++;
    }

    //
    while(l + blk_sz - 1 <= r){

        blk_num = l/blk_sz;
        add_value[blk_num] += val;
        l += blk_sz;
    }

    blk_num = l / blk_sz;
    while(l<=r){
        block[blk_num][ar[l]]--;

        ar[l] += val;
        block[blk_num][ ar[l] ]++;

        l++;
    }
}

int query(int l,int r)
{
    int cnt=0,val,idx;

    blk_num = l/blk_sz;

    while(l<=r && l%blk_sz!=0){
        idx = ar[l] + add_value[blk_num];

        if(mark[idx]) cnt++;

        l++;
    }
    while( l + blk_sz - 1 <= r){

        blk_num = l/blk_sz;

        for(int i=0;i<30;i++){
            idx = lucky[i] - add_value[blk_num];

            if(idx>=0 && block[blk_num][idx]>0){
                cnt += block[blk_num][idx];
            }
        }
        l += blk_sz;
    }

    blk_num = l/blk_sz;
    while(l<=r){
        if(mark[ar[l] + add_value[blk_num]]) cnt++;
        l++;
    }
    return cnt;
}
void build()
{
    int blk_idx = -1;

    blk_sz = sqrt(n)*3;

    for(int i=0;i<n;i++){

        if(i%blk_sz==0){
            blk_idx++;
        }
        block[blk_idx][ar[i]]++;
    }
}

int main()
{
    for(int i=0;i<30;i++) mark[lucky[i]] = 1;
    //
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++) scanf("%d ",&ar[i]);
    build();
    //
    char str[20];
    int l,r,v;
    while(q--){
        //getchar();
        scanf("%s ",str);

        if(strlen(str)==5){
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l-1,r-1));
        }
        else{
            //scanf("%d%d%d",&l,&r,&v);
            scanf("%d%d%d ",&l,&r,&v);
            update(l-1,r-1,v);
        }
    }
    return 0;
}
