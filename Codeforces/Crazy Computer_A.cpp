#include<bits/stdc++.h>
using namespace std;

int main()
{

    int c,n,cnt=1,a,b;
    cin>>n>>c;

    cin>>a;
    for(int i=1;i<n;i++){
        scanf("%d",&b);
        if(b-a<=c) cnt++;
        else if(b-a>c) cnt=1;
        a=b;
    }
    cout<<cnt<<endl;

return 0;
}
