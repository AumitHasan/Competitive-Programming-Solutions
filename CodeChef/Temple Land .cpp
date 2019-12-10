#include<bits/stdc++.h>
using namespace std;

int ar[105];

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

        bool flag = false;
        if(n%2==0) flag = true;
        else{
            int in = n/2 + 1;
            if(ar[in]!=in || ar[1]!=1 || ar[n]!=1) flag = true;
            else{
                for(int i=in;i>0;i--){
                    if(ar[i]!=i) flag = true;
                }
                int x = in;
                for(int i=in;i<=n;i++){
                    if(ar[i]!=x) flag = true;
                    x--;
                }
            }
        }
        if(flag) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
