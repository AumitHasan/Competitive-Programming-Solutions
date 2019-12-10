#include<bits/stdc++.h>
using namespace std;
#define mx 9

int comb[8],in,x,y,len,now;
char word[101][300],srule[10000];

void backtrack(int att,int n)
{
    if(att==n){
        x=-1;
        for(int j=0;j<len;j++){
            if(srule[j]=='0') printf("%d",comb[++x]);
            else cout<<word[now];
        }
        printf("\n");
        return ;
    }

    for(int i=0;i<10;i++){

        comb[att] = i;
        backtrack(att+1,n);
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);
    int w,rule;
    while(~scanf("%d",&w)){

        printf("--\n");

        int num=0;

        for(int i=0;i<w;i++) cin>>word[i];

        scanf("%d",&rule);

        for(int kk=0;kk<rule;kk++){

            cin>>srule;
            len = strlen(srule);

            num=0;
            for(int i=0;i<len;i++){
                if(srule[i]=='0') num++;
            }

            for(int i=0;i<w;i++){
                now = i;
                backtrack(0,num);
            }

        }
    }
return 0;
}
