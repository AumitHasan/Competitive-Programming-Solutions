#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k,pass,need,x,y,ind;
    while(1){
        scanf("%d%d%d",&n,&m,&k);
        if(!n || !m || !k) break;

        pass = n/2 + 1;
        if(m>=pass) cout<<0<<endl;
        else{
            need = pass-m;
            ind = n - m - k;
            if(need<=ind) cout<<need<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}
