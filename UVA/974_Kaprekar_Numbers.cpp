#include<bits/stdc++.h>
using namespace std;

int kap[40007];

void pre_kap()
{

    for(int i=2;i<=40000;i++)
    {
        int n=i*i;
        int x=0,a=0;
        int num=i,d=i*i;
        //cout<<n<<endl;
        int len=-1;

        while(d>0){
            d/=10;
            len++;

        }

        int l = len;
        //cout<<l<<endl;
        len = pow(10,len);

        for(int k=0;k<l;k++)
        {
            x = n/len;
            a = n%len;
            //cout<<x<<" "<<a<<endl;
            len/=10;
            if(x+a==num && x>0 && a>0){
                kap[i]=1;
                break;
            }
        }

    }
}
int main()
{
    pre_kap();
    int T,N=0;
    cin>>T;
    while(++N<=T)
    {
        int i,j;
        cin>>i>>j;
        int c=0;

        printf("case #%d\n",N);

        for(int k=i;k<=j;k++)
        {
            if(kap[k]==1){
                cout<<k<<endl;
                c=1;
            }
        }
        if(c==0) cout<<"no kaprekar numbers"<<endl;

        if(N!=T) cout<<endl;
    }

return 0;
}
