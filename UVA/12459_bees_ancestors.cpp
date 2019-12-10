#include<bits/stdc++.h>
using namespace std;

int main(){

    long long bee[81],i,gen;
    bee[0]=0;
    bee[1]=1;
    bee[2]=2;

    for(i=3;i<=80;i++)
        bee[i] = bee[i-1]+bee[i-2];

    while(1)
    {
        scanf("%lld",&gen);
        if(gen==0) return 0;

        printf("%lld\n",bee[gen]);
    }

return 0;
}
