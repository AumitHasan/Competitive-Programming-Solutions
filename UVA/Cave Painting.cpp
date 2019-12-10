#include<bits/stdc++.h>
using namespace std;

int ar[100000];

int main()
{
    long long int n,k;
    cin>>n>>k;

    for(int i=1;i<=min(100ll,k);i++){
        if(ar[n%i]){
            cout<<"No"<<endl;
            return 0;
        }
        else ar[n%i]++;
    }
    cout<<"Yes"<<endl;
}
