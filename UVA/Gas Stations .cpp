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

int G,L,x,r;
bool flag[10007];

struct info{
    int s,e;
    bool operator<(const info& a) const
    {
        return s<a.s;
    }
}ar[10007];

int main()
{
    while(1){
        scanf("%d %d",&L,&G);
        if(!L && !G) break;

        for(int i=0;i<G;i++){
            scanf("%d %d",&x,&r);
            ar[i].s = x-r;
            ar[i].e = x+r;
        }
        sort(ar,ar+G);

        int c=0,pos = 0,idx=-1,del=0;

        while(1){
            int x = idx,last=0;

            for(int i=idx+1;i<G;i++){

                if(ar[i].s<=pos){
                    if(last<ar[i].e){
                        last = ar[i].e;
                        idx = i;
                    }
                }
            }

            if(idx>x){
                if(pos<last){
                    pos = last;
                    flag[idx] = 1;
                }
            }
            else break;

            if(pos>=L) break;
        }

        for(int i=0;i<G;i++){
            if(!flag[i]) c++;
            flag[i] = 0;
        }

        if(pos<L) printf("-1\n");
        else printf("%d\n",c);
    }
    return 0;
}

