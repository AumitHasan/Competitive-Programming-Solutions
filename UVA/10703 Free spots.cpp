#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w,h,n,a,b,c,d;
    while(1){
        scanf("%d %d %d", &w, &h, &n);
        if(w==0 and h==0 and n==0) break;

        bool ar[501][501];
        while(n--){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            int x = min(b,d);
            int y = max(b,d);
            for(int i=x;i<=y;i++){
                for(int j=a;j<=c;j++) ar[i][j]=true;
                for(int j=a;j>=c;j--) ar[i][j]=true;
            }
        }
        int c=0;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(ar[i][j]==true) c++;
            }
        }
        int pnt = (w*h)-c;
        if(pnt==0) printf("There is no empty spots.\n");
        else if(pnt==1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n",pnt);

    }
}
