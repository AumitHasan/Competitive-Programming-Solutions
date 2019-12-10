#include<bits/stdc++.h>
using namespace std;

int used[52],num[6],found,i;

void backtrack(int ii,int val)
{
    //if(found) return ;
    if(ii==6 and val==23){
        found=1;
        return ;
    }
    else{
    for(int i=1;i<=5;i++){
        if(!used[i]){

            used[i] = 1;

            backtrack(ii+1,val+num[i]);
            backtrack(ii+1,val*num[i]);
            backtrack(ii+1,val-num[i]);

            used[i] = 0;
        }
    }
    }
}
int main()
{
    while(1){
        scanf("%d %d %d %d %d",&num[1] ,&num[2] ,&num[3] ,&num[4] ,&num[5]);
        if(num[1]==0 and num[2]==0 and num[3]==0 and num[4]==0 and num[5]==0) break;
        found = 0;
        for(int i=1;i<=5;i++){
            used[i] = 1;
            backtrack(2,num[i]);
            used[i] = 0;
            if(found) break;
        }
        if(found) printf("Possible\n");
        else printf("Impossible\n");
        memset(used,0,sizeof(used));
    }
    return 0;
}
