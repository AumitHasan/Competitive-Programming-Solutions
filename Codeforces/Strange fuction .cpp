#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

double x,y,ar[10];

double clc(double x)
{
    x = x*1.0;
    return 6.0*x*x*x*x*x*x*x + 8.0*x*x*x*x*x*x + 7.0*x*x*x + 5.0*x*x - y*x;
}
void simAnn()
{
    double ans = min(clc(0),clc(100.0));

    int i=0,itr=1000;
    double cost=101,cur=0,next1,next2;

    while(++i<itr){
        next1 = cur + cost;
        next2 = cur - cost;
        bool flag = false;
        //
        if(next1<=100){
            double tmp = clc(next1);
            if(tmp<ans){
                ans = tmp;
                flag = true;
                cur = next1;
            }
        }
        //
        if(next2>=0){
            double tmp = clc(next2);
            if(tmp<ans){
                ans = tmp;
                flag = true;
                cur = next2;
            }
        }
        //
        if(!flag) cost = cost / 1.9;
    }
    printf("%.4f\n",ans);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>y;
        simAnn();
    }
    return 0;
}
