#include<bits/stdc++.h>
using namespace std;

#define mx 10000001

int arr[mx];
int prime[664579];
bool bol[mx];

void seive()
{
    int in=-1;
    prime[++in]=2;
    for(int i=3;i<3162;i+=2)
    {
        if(bol[i]==false){
            prime[++in]=i;
            for(int j=i*i;j<mx;j+=2*i) bol[j]=true;
        }
    }
    for(int i=3163;i<mx;i+=2)
        if(bol[i]==false) prime[++in]=i;
    //cout<<in;
    in=0;
    arr[1]=arr[2]=0;
    for(int i=3;i<mx;i+=2)
    {
        if(bol[i]==false) arr[i]=++in;
        else arr[i]=in;
        arr[i+1]=in;
    }
}
int main()
{
    seive();
    //for(int i=9999980;i<10000001;i++) cout<<arr[i]<<" ";
    int low,high;
    while(~scanf("%d%d",&low,&high))
    {
        int l,add=0,ll;
        l=ll=arr[low];
        if(low%2!=0 && bol[low]==false) l--;
        else ll++;

        for(int i=1;i<=l;i++)
        {
            for(int j=l;j>i;j--)
            {
                if(i==j) continue;
                if(prime[i]+prime[j]<=high && prime[i]+prime[j]>=low){
                        //add+=j-i+1; cout<<i<<" "<<j+1<<" "<<add<<endl;l=j+1;
                    add++;
                }else break;
            }
        }
        int c=0;
        int i=ll;
        for(int i=ll;i<arr[high];i++)
        {
            if(prime[i]+prime[i+1]>high)
            {
                for(int j=i-1;j>0;j--){
                    if(i==j) continue;
                    if(prime[i]+prime[j]<=high && prime[i]+prime[j]>=low){
                        add+=j;
                    }else break;
                }
            }
            else{
                int x = ll;
                for(int j=arr[high];j>x;j--){}
            }
        }
        cout<<add<<endl;
    }

return 0;
}
