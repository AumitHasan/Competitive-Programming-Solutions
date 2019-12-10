#include<bits/stdc++.h>
using namespace std;

#define mx 100007
#define mem(a,b) memset(a,b,sizeof(a))

int ar[mx],tree[mx*3],check[mx];
struct st{
    int s,e,cnt;
}clc[mx];

void build(int node,int i,int j)
{
    if(i==j){
        //cout<<clc[i].s<<" "<<clc[i].e<<" "<<clc[i].cnt<<endl;
        tree[node] = clc[i].cnt;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    build(left,i,mid);
    build(right,mid+1,j);

    tree[node] = max(tree[left],tree[right]);
}
int query(int node,int i,int j,int qs,int qe)
{
    if(qs>j || qe<i) return 0;
    if(i>=qs && j<=qe){
        return tree[node];
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (i + j) / 2;

    int a = query(left,i,mid,qs,qe);
    int b = query(right,mid+1,j,qs,qe);

    return max(a,b);
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n,q;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        scanf("%d",&q);

        mem(check,0);
        mem(clc,0);

        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);
        ar[0] = 1e8;
        int in = 0;
        for(int i=1;i<=n;i++){
            if(ar[i]!=ar[i-1]) in++;
            check[i] = in;
        }
        for(int i=1;i<=n;i++){
            clc[check[i]].cnt++;
            if(clc[check[i]].s==0){
                clc[check[i]].s = i;
                clc[check[i]].e = i;
            }
            else clc[check[i]].e = i;
        }
//        for(int i=1;i<=n;i++){
//            cout<<check[i]<< " "<<in<<endl;
//        }
        build(1,1,in);
        //

        int s,e,fre,x,y;
        while(q--){
            scanf("%d %d", &s, &e);

            if(check[s]==check[e]){
                printf("%d\n",e - s + 1);

            }
            else{
                fre = clc[check[s]].e - s + 1;
                fre = max(fre, e - clc[check[e]].s + 1);
                x = check[s] + 1;
                y = check[e] - 1;
                if(x<=y){
                    fre = max(fre, query(1,1,in,x,y));
                }
                printf("%d\n",fre);
            }
        }

    }
}
