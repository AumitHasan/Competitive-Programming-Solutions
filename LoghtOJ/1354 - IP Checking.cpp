#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[4],n[4],T,N=0,ar[9];
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
        scanf("%d.%d.%d.%d",&n[0],&n[1],&n[2],&n[3]);
        int r=0;
        for(int i=0;i<4;i++){
            int sum=0,c=-1,aa=n[i];
            while(aa>0){
                ++c;
                int x = aa%10;
                aa/=10;
                sum += x*pow(2,c);
            }
            if(a[i]!=sum){
                r=1;
                break;
            }
        }
        if(r==0) printf("Case %d: Yes\n",N);
        else printf("Case %d: No\n",N);
    }
    return 0;
}

