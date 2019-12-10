#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,m,n;
    while(1){
        scanf("%d",&t);
        if(t==0) break;
        for(int i=1;i<=t;i++){
            scanf("%d%d",&m,&n);
            if(m==0 or n==0) cout<<"divisa"<<endl;
            else if(m>0){
                if(n>0) cout<<"NE"<<endl;
                else cout<<"SE"<<endl;
            }
            else if(m<0){
                if(n>0) cout<<"NO"<<endl;
                else cout<<"SO"<<endl;
            }
        }
    }
    return 0;
}
