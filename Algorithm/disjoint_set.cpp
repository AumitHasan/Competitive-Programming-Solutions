#include<bits/stdc++.h>
using namespace std;
#define mx 11

int prnt[mx];

void mrg(int x,int y)
{
    prnt[y]=prnt[x];
    return;
}
int fnd(int i)
{
    if(prnt[i]==i) return i;

    while(prnt[i]!=i){
        prnt[i]=prnt[prnt[i]];
        i = prnt[i];
    }

    return i;
}
int main()
{
    for(int i=0;i<mx;i++) prnt[i]=i;

    while(1)
    {
        int op,x,y;
        scanf("%d",&op);
        scanf("%d%d",&x,&y);

        if(op==1){
            if(fnd(x)==fnd(y)){
                printf("%d and %d are friends\n",x,y);
                cout<<prnt[x]<<" "<<prnt[y]<<endl;
            }
            else{
                printf("%d and %d are not friends\n",x,y);
                cout<<prnt[x]<<" "<<prnt[y]<<endl;
            }
        }
        else if(op==2){

            int a = fnd(x);
            int b = fnd(y);
            if(a==b){
                printf("%d and %d are friends\n",x,y);
                cout<<prnt[x]<<" "<<prnt[y]<<endl;
            }
            else{
                mrg(x,y);
                cout<<prnt[x]<<" "<<prnt[y]<<endl;
            }
        }
        else break;
    }

return 0;
}
