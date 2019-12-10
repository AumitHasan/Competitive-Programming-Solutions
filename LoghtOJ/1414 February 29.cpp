#include<bits/stdc++.h>
using namespace std;

long long leap(long long y){

    if((y%4==0 && y%100!=0) || (y%400==0))
        return 1;

    else return 0;
}
int main(){


    int N=0,T;
    string str[]={"a","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November","December"};
    cin>>T;
    while(++N <=T)
    {
        char s1[20],s2[20];
        long long d1,d2,y1,y2,y=0,i,c=0,m1,m2,res;

        scanf("%s %lld,%lld",s1,&d1,&y1);
        scanf("%s %lld,%lld",s2,&d2,&y2);
        for(int i=1;i<=12;i++){
            if(s1==str[i]) m1=i;
            if(s2==str[i]) m2=i;
        }



        if(leap(y1)){
            if(m1<=2) y1--;
        }
        if(m2==1) y2--;
        if(m2==2 and d2<29) y2--;
        printf("Case %d: ",N);
        long long ans = (y2/4 - y2/100 + y2/400) - (y1/4 - y1/100 + y1/400);
        if(ans<0) ans=0;


        printf("%lld\n",ans);

    }

return 0;
}
