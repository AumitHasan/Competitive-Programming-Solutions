#include<bits/stdc++.h>
using namespace std;
#define mx 17

int prime[]={2,3,5,7,11,13,17,19,23,29,31};
int used[mx],ring[mx],found,n;
bool check[40];

void backtrack(int idx)
{
    if(idx==n+1){
        if(check[1+ring[n]]){
            for(int j=1;j<=n;j++){
                printf("%d",ring[j]);
                if(j<n) printf(" ");
            }
            printf("\n");
            //getchar();
        }
        return ;
    }
    for(int i=2;i<=n;i++){

        if(!used[i] and check[i+ring[idx-1]]){

            used[i] = 1;
            ring[idx] = i;

            backtrack(idx+1);

            used[i] = 0;
        }
    }
}
int main()
{
    for(int i=0;i<11;i++) check[prime[i]]=true;
    int N=0;
    while(~scanf("%d",&n)){

        used[1] = 1;
        ring[1] = 1;
        if(N>0) printf("\n");
        printf("Case %d:\n",++N);
        backtrack(2);
    }
    return 0;
}
