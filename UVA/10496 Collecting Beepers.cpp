#include<bits/stdc++.h>
using namespace std;

int rs[23][3];

int main()
{
    int t,x,y,sx,sy,pnt;
    scanf("%d",&t);
    while(t--){
        memset(rs,0,sizeof(rs));
        int path=0,c=1000,a,in=-1,b;
        scanf("%d%d",&x,&y);
        scanf("%d%d",&sx,&sy);

        scanf("%d",&pnt);

        for(int i=1;i<=pnt;i++){
            scanf("%d%d",&x,&y);
            rs[++in][0]=x;
            rs[in][1]=y;
        }
        a=sx;
        b=sy;
        for(int i=0;i<pnt;i++){
            int val=1000,ps=-1;
            for(int j=0;j<=in;j++){
                if(val>(abs(a-rs[i][0])+abs(rs[i][1]-b)) and rs[i][2]==0){
                    val = abs(a-rs[i][0])+abs(rs[i][1]-b);
                    ps=i;
                }
            }
            cout<<val<<" "<<rs[ps][0]<<" "<<rs[ps][1]<<" "<<a<<" "<<b<<endl;

            path+=val;
            a=rs[ps][0];
            b=rs[ps][1];
            rs[ps][2]=1;
        }
        path += abs(a-sx)+abs(b-sy);
        cout<<path<<endl;
    }
    return 0;
}
