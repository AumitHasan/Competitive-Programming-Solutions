#include<bits/stdc++.h>
using namespace std;

int ar[1000];

int main()
{
    char ch;
    int T,N=0,n;
    cin>>T;

    while(++N<=T){
        scanf("%d ",&n);

        for(int i=0;i<n;i++){
            scanf("%c",&ch);
            if(ch=='.') ar[i]=0;
            else ar[i]=1;
        }

        int in=-1,res=0,c=0;
        while(++in<n){
            if(ar[in]==0) c++;
            else{
                if(c==2) res++;
                else if(c==1){
                    res++;
                    ++in;
                }
                c=0;
                //cout<<in<<endl;
            }
            if(c==3){
                res++;
                c=0;
            }
        }
        //cout<<c<<endl;
        if(c>0) res++;

        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
