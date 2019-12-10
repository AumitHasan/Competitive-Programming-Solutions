#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii acos(-1.0)

#define mx 50007

int n,A[mx],B[mx];


void refresh()
{
    for(int i=0;i<mx;i++) A[i] = B[i] = 0;
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        refresh();
        //
        scanf("%d",&n);
        int x=-1,y=-1;

        for(int i=0;i<n;i++){
            if(i%2==0){
                scanf("%d",&A[++x]);
            }
            else{
                scanf("%d",&B[++y]);
            }
        }
        sort(A,A+x+1);
        sort(B,B+y+1);

        if(x>y) B[x] = A[x];
        if(x<y) A[y] = B[y];

        int last = max(x,y);

        printf("Case #%d: ",N);

        bool flag = false;

        for(int i=0;i<last;i++){
            if(A[i] > B[i]){
                printf("%d\n",i*2);
                flag = true;
                break;
            }
            else if(B[i] > A[i+1]){
                printf("%d\n",i*2+1);
                flag = true;
                break;
            }
            else if(A[i+1] > B[i+1]){
                printf("%d\n",(i+1)*2);
                flag = true;
                break;
            }
        }

        if(!flag) printf("OK\n");
    }
    return 0;
}
