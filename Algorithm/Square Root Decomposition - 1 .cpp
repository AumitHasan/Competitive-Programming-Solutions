#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define sqrsize 320

int ar[MAX],block[sqrsize];
int n,blk_sz;
int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};


void update(int idx,int val)
{
    int block_number = idx/blk_sz;
    block[block_number] += val - ar[idx];
    ar[idx] = val;
}
int query(int l,int r)
{
    int sum = 0;
    while(l<r && l%blk_sz!=0 && l!=0){
        sum += ar[l];
        l++;
    }
    while( l + blk_sz -1 <=r){
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while(l<=r){
        sum += ar[l];
        l++;
    }
    return sum;
}
void build()
{
    int blk_idx = -1;

    blk_sz = sqrt(n);

    for(int i=0;i<n;i++){
        ar[i] = input[i];
        if(i%blk_sz==0){
            blk_idx++;
        }
        block[blk_idx] += ar[i];
    }
}
int main()
{
    n = sizeof(input)/sizeof(input[0]);
    build();

    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(8,8) : " << query(8, 8) << endl;
}
