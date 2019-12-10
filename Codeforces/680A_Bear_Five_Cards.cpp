#include<bits/stdc++.h>
using namespace std;

int a[101],com[15];

int main()
{
    int b,sum=0;
    for(int i=1;i<=5;i++){
        scanf("%d",&b);
        a[b]++;
        sum+=b;
    }
    int in=-1;
    for(int i=1;i<=100;i++)
    {
        if(a[i]==2) com[++in] = i*2;
        if(a[i]>=3) com[++in] = i*3;
    }
    int x = *max_element(com,com+15);

    printf("%d\n",sum-x);

return 0;
}
