#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,num,i,x;

    cin>>n;

    while(n--){

        cin>>num;
        int a[10]={0};


        for(i=1;i<=num;i++){

            if(i<10) a[i]++;
            else{
                x=0;
                x=i;
                while(x>0){

                    a[x%10]++;
                    x/=10;
                }
            }
        }

        for(i=0;i<10;i++){
            cout<<a[i];
            if(i<9)
                cout<<" ";
            else   cout<<endl;

        }
    }

return 0;
}
