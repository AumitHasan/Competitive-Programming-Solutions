#include<bits/stdc++.h>
using namespace std;

#define mx 100007

int tree[mx];

void update(int idx,int x,int n)
{
    while(idx<=n){
        tree[idx] += x;
        idx += idx & (-idx);
    }
}
int query(int idx)
{
    int sum = 0;
    while(idx>0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
int main()
{
    for(int i=1;i<=9;i++){
        update(i,i,9); // for every index set value
    }
    cout<<query(9)<<endl;
}
