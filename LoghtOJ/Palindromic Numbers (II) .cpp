#include<bits/stdc++.h>
using namespace std;

int ar[11];

int main()
{
    string str;
    int T,N=0,num;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&num);

        int in=-1;
        while(num>0){
            ar[++in] = num%10;
            num/=10;
        }

        int flag=0,s=0,e=in;
        while(s<=e){
            if(ar[s]!=ar[e]){
                flag = 1;
                break;
            }
            s++;
            e--;
        }

        if(flag) printf("Case %d: No\n",N);// flag ? "Yes" : "No");
        else printf("Case %d: Yes\n",N);// flag ? "Yes" : "No");
    }
    return 0;
}
