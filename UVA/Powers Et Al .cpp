#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d %d",&a ,&b) and a and b){
        long long int mul=1;
        for(int i=0;i<b;i++){
            mul *= a;
            cout<<mul<<endl;
        }
    }
}
