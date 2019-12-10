#include<bits/stdc++.h>

using namespace std;

void prnt(int hour,int m)
{
    m %= 60;

    if(hour<10) printf("0%d:",hour);
    else printf("%d:",hour);
    //
    if(m<10) printf("0%d\n",m);
    else printf("%d\n",m);
}
int main()
{
    int t,h,m;
    cin>>t;
    while(t--){
        scanf("%d:%d",&h,&m);
        //
        if((h == 6 || h == 12) && m==0){
            prnt(h,m);
        }
        else if(h>=9 && h<12){
            h = h + ((12-h) * 2);
            if(m>0) h--;
            if(h>12) h %= 12;
            //
            m = abs(60-m);
            //
            prnt(h,m);
        }
        else if(h==12 || h<3){
            if(h<12) h += 12;
            //
            h = h - ((h-12) * 2);
            if(m>0) h--;
            //
            m = abs(60-m);
            //
            prnt(h,m);
        }
        else if(h>=3 && h<6){
            h = h + ((6-h) * 2);
            if(m>0) h--;
            //
            m = abs(60-m);
            //
            prnt(h,m);
        }
        else if(h>=6 && h<9){
            h = h - ((h-6) * 2);
            if(m>0) h--;
            //
            m = abs(60-m);
            //
            prnt(h,m);
        }

    }
    return 0;
}
