#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c=0;
    cin>>a>>b;

    if(a<=2&&b<=2){
        cout<<c<<endl;
        return 0;
    }

    while(1)
    {
        int y = max(a,b);
        int z = min(a,b);
        a = z;
        b = y;

        //int x = b/2;
        //if(b%2==0) x--;
        //c+=x;
        //b -= x*2;
        //a+=x;

        while(1){
            if(b<=2) break;
            b-=2;
            c++;
            a++;
            //cout<<a<<" "<<b<<endl;
            if(a>b) break;
        }




        if(a<=2&&b<=2) break;
    }
    cout<<++c<<endl;

return 0;
}
