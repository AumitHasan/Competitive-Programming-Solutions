#include<bits/stdc++.h>
using namespace std;

#define MAX 100007
#define mem(a,b) memset(a,b,sizeof(a))

int n,num[30250],in,digit[20],used[20],ar[20];

bool ck(int x)
{
    while(x>0){

    }
}
void nCr(int pos)
{
    if(pos>=5){
        int val = 0;
        for(int i=0;i<5;i++) val = (val*10) + digit[i];
        //num[++in] = val;
        //cout<<val<<" ";
        if(val%n==0 && val>0){
            int x = val/n;
            if(x>1000 && ck(x)){
                for(int i=0;i<5;i++) printf("%d",digit[i]);
                printf(" / ");
                if(x<10000) printf("0");
                printf("%d = %d\n",x,n);
            }
        }
        return ;
    }
    for(int i=0;i<10;i++){
        if(!used[i]){
            digit[pos] = i;
            used[i] = 1;
            nCr(pos+1);
            used[i] = 0;
        }
    }
    return;
}
int main()
{
    in = -1;

    //cout<<in;
    while(scanf("%d",&n) && n){
        nCr(0);
    }
}
