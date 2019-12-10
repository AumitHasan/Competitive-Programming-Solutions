#include<bits/stdc++.h>
using namespace std;

int used[28],num[28],c,n,k;

void backtrack(int att)
{
    if(c==k) return;

    if(att==n){
        c++;
        for(int j=0;j<n;j++) printf("%c",num[j]+65);
        printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i] = 1;
            num[att] = i;
            backtrack(att+1);
            used[i] = 0;
        }
    }
}
int main()
{
    int T,N=0;
    scanf("%d",&T);
    while(++N<=T){
        c=0;
        scanf("%d %d",&n ,&k);
        printf("Case %d:\n",N);
        backtrack(0);
    }
    return 0;
}
