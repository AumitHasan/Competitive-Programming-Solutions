#include<stdio.h>
int main(){

    long long t,goal,dif,i,team1,team2;

    scanf("%lld",&t);

    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&goal,&dif);

        if(goal<dif)
            printf("impossible\n");
        else
        {

            team1=(goal/2)+(dif/2);
            team2=goal-team1;
            printf("%lld %lld\n",team1,team2);
        }

    }

return 0;
}
