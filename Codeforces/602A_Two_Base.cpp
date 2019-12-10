
#include<bits/stdc++.h>
using namespace std;
#define LL "%I64d"

int main(){

    vector <int> v;
    vector <int> vec;
    long long i,n,m,by,y,x,j,bx;

    cin>>n>>bx;
    for(i=0;i<n;i++)
    {
        scanf(LL,&x);
        v.push_back(x);
    }
    cin>>m>>by;
    for(i=0;i<m;i++)
    {
        scanf(LL,&x);
        vec.push_back(x);
    }

    if(bx!=2 && by!=2)
    {
        if(n>m && bx>by){
            cout<<">"<<endl;
            return 0;
        }
        else if(m>n && by>bx){
            cout<<"<"<<endl;
            return 0;
        }
    }

    x=j=0;
    for(i=n-1;i>=0;i--) //convert number
    {
        x+=v[i]*pow(bx,j);
        j++;
    }

    y=j=0;
    for(i=m-1;i>=0;i--) //convert number
    {
        y+=vec[i]*pow(by,j);
        j++;
    }
cout<<x<<" "<<y<<endl;
    if(x>y)
        cout<<">"<<endl;
    else if(x<y)
        cout<<"<"<<endl;
    else
        cout<<"="<<endl;

return 0;
}
