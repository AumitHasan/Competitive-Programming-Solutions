#include<bits/stdc++.h>
using namespace std;

int a[2001];
void seive(){

    for(int i=0;i<=2001;i++)
    	a[i]=0;

    for(int i=4;i<=2001;i+=2)
        a[i]=1;
    for(int i=3;i<=sqrt(2001);i+=2)
    {
        if(a[i]==0)
        {
            for(int j=i*i;j<=2001;j+=i)
                a[j]=1;
        }
    }

    a[0]=1;
    a[1]=1;
    a[2]=0;

}

int main(){

    seive();

    int i,j,T,N=0;

    cin>>T;
    while(++N <=T)
    {
        string s;
        int check[75]={0},c=0;
        cin>>s;
        for(i=0;i<s.size();i++)
            check[s[i]-48]++;

        printf("Case %d: ",N);
        for(i=0;i<75;i++)
        {
           if(a[check[i]]==0){
                printf("%c",i+48);
                c=1;
            }
        }

        if(c==0)
            cout<<"empty";

        cout<<endl;
    }


return 0;
}
