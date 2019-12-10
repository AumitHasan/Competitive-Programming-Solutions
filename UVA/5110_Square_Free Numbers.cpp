#include<bits/stdc++.h>
using namespace std;


long a[1000001];
vector <long> v;

void seive(){

    long i,j,N=1000000;
    for(i=0;i<=N;i++)
        a[i]=0;

    for(i=4;i<N;i+=2)
        a[i]=1;

    v.push_back(2);
    for(i=3;i<sqrt(N);i+=2)
    {
        if(a[i]==0){
            v.push_back(i);
            for(j=i*i;j<=N;j+=i)
                a[j]=1;
        }
    }

    a[0]=1;
    a[1]=1;
    a[2]=0;

}

int main(){

    seive();

    long test,n,i,c,max,s=0;
    cin>>test;

    while(test--){

        cin>>n;

        s=0;
        max=0;
        s=v[0];

        for(i=0;i<v.size() && v[i]*v[i]<=n;i++)
        {
            c=s=0;
            s=v[i+1];

            if(n%v[i]==0){

                while(n%v[i]==0){
                    n/=v[i];
                    c++;
                }
            }

            if(c==2){
               continue;
            }


            if(c<max || i==0)
                max=c;

        }
        if(max==0)
            max++;

        cout<<max<<endl;
    }


return 0;
}
