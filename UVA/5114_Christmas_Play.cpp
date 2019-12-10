#include<bits/stdc++.h>
using namespace std;

int main(){

    long test,n,k,i,min,dif;

    cin>>test;
    while(test--){

        scanf("%ld %ld",&n,&k);
        long a[n];

        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);

        sort(a,a+n);

        if(k==1){
            cout<<'0'<<endl;
            continue;
        }

        min=0;
        for(i=0;i<=(n-k);i++)
        {
            dif=0;
            dif=a[i+k-1]-a[i];

            if(i==0 || dif<min)
                min=dif;
        }

        cout<<min<<endl;


    }


return 0;
}
