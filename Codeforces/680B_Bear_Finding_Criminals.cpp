
#include<bits/stdc++.h>
using namespace std;

int cr[101],com[15];

int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    a--;
    for(int i=0;i<n;i++) scanf("%d",&cr[i]);

    int i,j,k=1,c,cnt=0;
    i=j=c=0;

    if(cr[a]==1) c++;

    while(1)
    {
        i = a-k;
        j = a+k;
        k++;
        if(i<0){cnt=1; break;}
        if(j==n){cnt=2; break;}

        if(cr[i]==1 and cr[j]==1) c+=2;
    }

    if(cnt==1){
        for(int l=j;l<n;l++)
            if(cr[l]==1) c++;
    }
    if(cnt==2){
        for(int l=i;l>=0;l--)
            if(cr[l]==1) c++;
    }

    printf("%d\n",c);

return 0;
}
