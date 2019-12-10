#include<bits/stdc++.h>
using namespace std;

int num[]={4,7},c=0;
int a[40],in=-1;

void num_gen(int i,int number)
{
    if(number>10000) return ;
    else if(number>0)  a[++in] = number; ++c;

    for(int j=0;j<2;j++){
        num_gen( i + 1, (number * 10) + num[j]);
    }
}
int main()
{
   cout<<0%6;
}


