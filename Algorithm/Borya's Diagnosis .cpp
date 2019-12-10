#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y,last,ans;
    cin>>n;

    cin>>x>>y;
    last = ans = x;

    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);

        for(int j=x;;j+=y){
            if(j>last){
                last = j;
                ans = j;
                break;
            }
        }
    }

    cout<<ans<<endl;
}
