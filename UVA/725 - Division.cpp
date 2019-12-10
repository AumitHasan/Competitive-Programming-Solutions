#include<bits/stdc++.h>
using namespace std;
#define mx 10

int used[mx],c,n,found;
bool check[10];
int num[5];//={0,1,2,3,4,5,6,7,8,9};

void backtrack(int att)
{
    if(found) return;
    if(att>4){

        int y=0,cnt=0;
        for(int j=0;j<5;j++) y = (y*10)+num[j];
        if(y*n>99999){
            found=1;
            return ;
        }
        if(y*n<=99999){
            int res=y*n;
            for(int k=0;k<5;k++){
                check[num[k]] = 1;
                check[res%10] = 1;
                res/=10;
            }
            for(int k=0;k<mx;k++){
               // printf("%d ",check[k]);
                if(check[k]==1) cnt++;
            }
            //cout<<endl<<res<<" "<<y<<" "<<n<<" "<<cnt<<endl;
            //getchar();
            if(cnt==10){
                ++c;
                printf("%d / ",y*n);
                for(int j=0;j<5;j++) printf("%d",num[j]);
                printf(" = %d\n",n);
            }
            memset(check,0,sizeof(check));
        }
        return;
    }

    for(int i=0;i<mx;i++){

        if(!used[i]){
            used[i]=1;
            num[att]=i;
            backtrack(att+1);
            used[i]=0;
            num[att]=0;
        }
    }
}
int main()
{
    int s=0;
    while(1){
        s++;
        scanf("%d",&n);
        if(n==0) break;
        if(s>1) printf("\n");
        c=0;
        found=0;
        for(int i=0;i<5;i++){
            num[0] = i;
            used[i] = 1;
            backtrack(1);
            used[i] = 0;
        }
        if(c==0) printf("There are no solutions for %d.\n",n);
    }
    return 0;
}
