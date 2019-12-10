#include<bits/stdc++.h>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 80

int n,ar[MAX*2][MAX*2];


int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&ar[i][j]);
                    ar[i][j+n] = ar[i+n][j] = ar[i+n][j+n] = ar[i][j]; // create grid
            }
        }
        for(int i=0;i<n*2;i++){ // prefix sum
            for(int j=0;j<n*2;j++){
                if(i>0) ar[i][j] += ar[i-1][j];
                if(j>0) ar[i][j] += ar[i][j-1];
                if(i>0 && j>0) ar[i][j] -= ar[i-1][j-1];
            }
        }
        int res = -1e8,tmp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // (i,j) && (k,l)
                for(int k=i;k<i+n;k++){
                    for(int l=j;l<j+n;l++){
                        tmp = ar[k][l];
                        if(i>0) tmp -= ar[i-1][l];
                        if(j>0) tmp -= ar[k][j-1];
                        if(i>0 && j>0) tmp += ar[i-1][j-1];
                        res = max(res,tmp);
                    }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

