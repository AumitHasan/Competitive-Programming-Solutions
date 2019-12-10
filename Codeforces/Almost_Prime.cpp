#include<iostream>
using namespace std;
#include<math.h>

void seive(int a[],int n){

    int root,i,j;
    root=sqrt(n);
    for(i=3;i<=n;i+=2)
        a[i]=0;
    for(i=3;i<=root;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=n;j+=i)
                a[j]=1;
        }
    }

    a[0]=1;
    a[1]=1;
    a[2]=0;
}

int main(){

    int n,c=0,ap=0,i,j;
    cin>>n;
    int a[n];
    seive(a,n);


    if(n<6)
    {
        cout<<ap;
    }
    else{
        for(i=6;i<=n;i++)
        {
            c=0;
            if(i%2==0)
                c++;
            for(j=3;j<=i/2;j+=2)
            {
                if(a[j]==0)
                {
                    if(i%j==0)
                        c++;
                    else
                        continue;

                    if(c>2)
                        break;
                }
                if(c>2)
                        break;

            }
             if(c==2)
                    ap++;

        }
        cout<<ap;

    }


return 0;
}
