#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long num,div;
    cin>>num;

    cout<<"Prime factor of "<<num<<" : ";

    div = 2;

    while(num!=0){
        if(num%div!=0)
            div = div + 1;
        else {
            num = num / div;
            cout<<div<<" ";
            if(num==1)
                break;
        }
    }
return 0;
}
