#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n,maxSum;
int ar[50][50],tmp[50],row,col,in,zero[100];
char str[30][30],clear[6];

int kadane(int R)
{
    int sum=0,local_start=0,resSum=0;


    for(int i=0;i<col;i++){
        sum += tmp[i];
        if(tmp[i]==0 || zero[i] || str[i][R]=='0'){

            sum = 0;
        }

        else if(sum>resSum){
            resSum = sum;

        }
    }
    /*if(finish != -1 ) return resSum;

    resSum = tmp[0];
    start =finish = 0;

    for(int i=0;i<row;i++){
        if(tmp[i]>resSum){
            start = finish = i;
        }
    }*/
    return resSum;
}
int main()
{


    int T,N=0;
    scanf("%d",&T);

    gets(clear);;
    //for(int i=0;i<30;i++) ar[0][i] = 0;
    while(T--){

        maxSum = 0;
        gets(clear);
        gets(str[0]);

        in = -1;

        in++;
        col = strlen(str[0]);

        for(int i=1;i<col;i++) gets(str[i]);


        row = in+1;


        int left,right,sum=0;

        for(left=0;left<col;left++){
            mem(tmp,0);
            mem(zero,0);
            for(right=left;right<col;right++){

                for(int i=0;i<col;i++){
                    tmp[i] += str[i][right]-'0';

                    //if(left==9 && right==9) cout<<tmp[i];
                    if(str[i][right]=='0') zero[i] = 1;
                }
                //cout<<endl;
                sum = kadane(right);

                if(sum>maxSum){
                    maxSum = sum;

                }
            }
        }
        cout<<maxSum<<endl;
        if(T) puts("");
    }

    return 0;

}
