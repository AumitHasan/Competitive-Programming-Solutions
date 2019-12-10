#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
    if(x>y) swap(x,y);
    int a = y%x;
    if(a==0) return x;
    gcd(a,x);
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        int g[1005];
        g[0]=n;
        int in=0,j=-1;
        while(cin>>n&&n!=0) g[++in]=n;

        int dif[n];
        for(int i=0;i<in;i++)
        {
            if((g[i]<0&&g[i+1]<0) || (g[i]>0&&g[i+1]>0) ){
                int x = abs(abs(g[i])-abs(g[i+1]));
                if(x!=0) dif[++j]=x;

            }else{
                if(g[i]!=g[i+1]){
                    int x = abs(g[i])+abs(g[i+1]);
                    dif[++j]=x;
                }
            }
        }

        int d=dif[0];
        for(int i=1;i<=j;i++){
            d=gcd(d,dif[i]);
        }

        cout<<d<<endl;
    }
}
