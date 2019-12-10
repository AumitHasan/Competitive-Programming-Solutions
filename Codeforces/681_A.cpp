#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,c=0;
    scanf("%d",&T);
    while(T--)
    {
        string s;
        int a,b;
        cin>>s;
        scanf("%d%d",&a,&b);
        if(b>a&&a>=2400) c=1;
    }

    if(c==1) printf("YES\n");
    else printf("NO\n");

return 0;
}
