#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      107

////
int row,col,rx,cx,ar[2][mx],ans[mx][mx];


int main()
{
    scii(row,col);
    for(int i=0;i<row;i++){
        sci(ar[0][i]);
        rx ^= ar[0][i];
    }
    for(int i=0;i<col;i++){
        sci(ar[1][i]);
        cx ^= ar[1][i];
    }
    if(rx != cx){
        cout<<"NO"<<endl;
        return 0;
    }

    if(row==1 || col==1){
        if(row==1){
            for(int j=0;j<col;j++) cout<<ar[1][j]<<" ";
            cout<<endl;
        }
        else{
            for(int j=0;j<row;j++) cout<<ar[0][j]<<endl;
        }
        return 0;
    }

    if(row>col) for(int i=0;i<row;i++) swap(ar[0][i],ar[1][i]);

    int tmp = 0;
    for(int i=0;i<col-1;i++){
        ans[0][i] = ar[1][i];
        tmp ^= ar[1][i];
    }
    ans[0][col-1] = tmp ^ ar[0][0];

}
