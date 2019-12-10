#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d1[12],d2[12],n,m,b1,b2;
    unsigned long long n1=0,n2=0,j=1;

    cin>>n>>b1;
    for(int i=0;i<n;i++) scanf("%d",&d1[i]);
    cin>>m>>b2;
    for(int i=0;i<m;i++) scanf("%d",&d2[i]);

    for(int i=n-1;i>=0;i--)
    {
        n1 += d1[i]*j;
        j*=b1;
    }

    j=1;
    for(int i=m-1;i>=0;i--)
    {
        n2 += d2[i]*j;
        j*=b2;
    }

    //cout<<n1<<" "<<n2<<endl;
    if(n1==n2) printf("=\n");
    else if(n1>n2) printf(">\n");
    else printf("<\n");

return 0;
}
