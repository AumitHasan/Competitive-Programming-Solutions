#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,c,cnt;
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        while(n--)
        {
            c=0;
            for(int i=1;i<=m;i++){
                scanf("%d",&a);
                if(a!=0) c++;
            }
            if(c==m) cnt++;
        }
        printf("%d\n",cnt);
    }

return 0;
}
