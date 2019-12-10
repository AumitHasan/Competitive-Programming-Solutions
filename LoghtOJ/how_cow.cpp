
#include<iostream>

using namespace std;

int main(){

    int t,a,b,c,d,i,cow,x,y;
    cin>>t;

    for(i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":"<<endl;

        cin>>a>>b>>c>>d;
        cin>>cow;

        while(cow--){

            cin>>x>>y;

            if(x>=a && x<=c)
            {
                if(y>=b && y<=d)
                    cout<<"Yes"<<endl;
                else
                    cout<<"No"<<endl;
            }else
                cout<<"No"<<endl;
            x=y=0;

        }
        a=b=c=d=0;

    }


return 0;
}
