#include<bits/stdc++.h>
using namespace std;
#define mx 200001

int a[mx],b[mx];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);

    sort(a,a+n);
    sort(b,b+n);

    int c=0,i=0,j=0;
    while(i<n and j<n){
        if(b[j]>a[i]){
            c++;
            i++;
        }
        j++;
    }
    printf("%d\n",c);

    return 0;
}
