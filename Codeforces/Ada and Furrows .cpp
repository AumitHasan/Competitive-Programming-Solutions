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

#define mx 20007

bitset<mx>flag[mx];

int main()
{
    int q,x,y;
    char ch;
    scanf("%d",&q);
    while(q--){
        getchar();
        scanf("%c",&ch);
        scanf(" %d %d",&x,&y);
        //
        if(ch=='+'){
            flag[x][y] = 1;
        }
        else if(ch=='-'){
            flag[x][y] = 0;
        }
        else if(ch=='v'){
            printf("%d\n",(flag[x] | flag[y]).count());
        }
        else if(ch=='^'){
            printf("%d\n",(flag[x] & flag[y]).count());
        }
        else if(ch=='!'){
            printf("%d\n",(flag[x] | flag[y]).count() - (flag[x] & flag[y]).count());
        }
        else if(ch=='\\'){
            printf("%d\n",flag[x].count() - (flag[x] & flag[y]).count());
        }
    }
    return 0;
}
