#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,n,m,u,v;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
        }
        int man = n-(m*2);
        if(man%2==0) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
