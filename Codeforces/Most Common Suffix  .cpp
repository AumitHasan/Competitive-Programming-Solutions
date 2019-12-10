#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define bs 1000007
#define mem(a,b) memset(a,b,sizeof(a))
#define umap unordered_map


llu has,base[MAX];
int T,n,q,x,res[MAX];
char ch[MAX];
umap<llu,int>mp[MAX];

void hash_pw()
{
    base[0] = 1;
    for(int i=1;i<MAX;i++) base[i] = base[i-1] * bs;
}
int main()
{
    hash_pw();
    //
    scanf("%d", &T);
    while(T--){
        for(int i=1;i<MAX;i++){
            mp[i].clear();
            res[i] = 0;
        }
        //
        scanf(" %d %d", &n, &q);
        for(int k=0;k<n;k++){
            scanf(" %s", ch);
            int len = strlen(ch);
            has = 0;
            for(int i=1,j=len-1;i<=len;i++,j--){
                has = (has*bs) + ch[j];
                mp[i][has]++;
                res[i] = max(res[i],mp[i][has]);
            }
        }
        while(q--){
            scanf("%d", &x);
            printf("%d\n",res[x]);
        }

    }
}
