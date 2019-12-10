#include<bits/stdc++.h>
using namespace std;

#define MAX 200007
#define ll long long int
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int blk_num,blk_sz,n;
int ar[MAX];
long long int sum[500];

void update(int idx,int val)
{
    blk_num = idx / blk_sz;

    sum[blk_num] += val - ar[idx];

    ar[idx] = val;
}
long long int query(int l,int r)
{
    ll S = 0;
    while(l<=r && l%blk_sz!=0){
        S += ar[l];
        l++;
    }
    while(l + blk_sz - 1 <= r){
        blk_num = l / blk_sz;
        S += sum[blk_num];
        l += blk_sz;
    }

    while(l<=r){
        S += ar[l];
        l++;
    }
    return S;
}
void build()
{
    blk_sz = sqrt(n);
    int blk_idx=-1;
    for(int i=0;i<n;i++){
        if(i%blk_sz==0){
            blk_idx++;
        }
        sum[blk_idx] += ar[i];
    }
}

int main()
{
//    READ("in.txt");
//    WRITE("out.txt");

    int x,y,r,c=0;
    char str[10];

    while(scanf("%d ",&n) && n){
        c++;
        if(c>1) printf("\n");

        for(int i=0;i<n;i++) scanf("%d",&ar[i]);
        build();
        //
        printf("Case %d:\n",c);

        while(1){
            scanf("%s ",str);
            if(str[0]=='S'){
                scanf("%d %d", &x, &r);
                update(x-1,r);
            }
            else if(str[0]=='M'){
                scanf("%d %d", &x, &y);
                printf("%lld\n",query(x-1,y-1));
            }
            else break;
        }

        for(int i=0;i<=n;i++) ar[i]=0;
        for(int i=0;i<500;i++) sum[i]=0;
    }
}
