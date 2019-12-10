#include<iostream>
using namespace std;
#include<math.h>
#define N 1000000

char a[1000000];

void seive()
{
     int i,j,root;
     root = sqrt(N);

     //for(i=4;i<=N;i+=2)
       // a[i]=1;

     for(i=3;i<=root;i+=2)
     {
         if(a[i] != 1) // if(a[i] == 0)
         {
             for(j=i*i;j<=N;j+=i)
                a[j]=1;
         }
     }
     a[1]=1;
     a[2]=0;
}


int main()
{
    int s;
    seive();
    cin>>s;



return 0;
}
