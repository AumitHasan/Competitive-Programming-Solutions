#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,maxSum,start,finish,final_Top,final_Bottom,final_Left,final_Right;
int ar[101][101],tmp[101];

int kadane()
{
    int sum=0,local_start=0,resSum=0;
    finish=-1;

    for(int i=0;i<n;i++){
        sum += tmp[i];
        if(sum<0){
            local_start = i+1;
            sum = 0;
        }
        else if(sum>resSum){
            resSum = sum;
            start = local_start;
            finish = i;
        }
    }
    if(finish != -1 ) return resSum;

    resSum = tmp[0];
    start =finish = 0;

    for(int i=0;i<n;i++){
        if(tmp[i]>resSum){
            start = finish = i;
        }
    }
    return resSum;
}
int main()
{

    bool ck = false;
    int mn=-200;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&ar[i][j]);
            if(ar[i][j]==0) ck = true;
            if(ar[i][j]>mn && ar[i][j]<0) mn = ar[i][j];
        }
    }
    int left,right,sum=0;

    for(left=0;left<n;left++){
        mem(tmp,0);
        for(right=left;right<n;right++){
            for(int i=0;i<n;i++) tmp[i] += ar[i][right];

            sum = kadane();

            if(sum>maxSum){
                maxSum = sum;
                final_Top = start;
                final_Bottom = finish;

                final_Left = left;
                final_Right = right;
            }
        }
    }
    if(maxSum==0 && !ck) cout<<mn<<endl;
    else cout<<maxSum<<endl;

    return 0;
}
