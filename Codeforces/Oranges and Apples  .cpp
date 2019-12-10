#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
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

struct info{
    int apl,orng;
}ar[2*mx];

int ck[2*mx];

int main()
{

    int T,n;
    scanf("%d",&T);
    while(T--){
        ll apple=0,orange=0;

        scanf("%d",&n);

        int sf = 2*n - 1;
        for(int i=0;i<sf;i++) ck[i] = i;

        for(int i=0;i<sf;i++){
            scanf("%d %d", &ar[i].apl, &ar[i].orng);
            apple += ar[i].apl;
            orange += ar[i].orng;
        }
        apple = apple/2 + (apple%2);
        orange = orange/2 + (orange%2);


        while(1){
            ll x=0,y=0;
            random_shuffle(ck,ck+sf);
            //for(int i=0;i<sf;i++) cout<<ck[i]<<" ";
            //cout<<endl;
            for(int i=0;i<n;i++){
                x += ar[ck[i]].apl;
                y += ar[ck[i]].orng;
            }
            if(x >= apple && y >= orange){
                printf("YES\n");
                for(int i=0;i<n;i++){
                    printf("%d",ck[i]+1);
                    if(i==n-1) printf("\n");
                    else printf(" ");
                }
                break;
            }
        }
    }
}
