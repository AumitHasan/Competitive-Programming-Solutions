#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define M 100003

int ar[M],n;

int binSearch(int lo,int hi)
{
    int temp,k=0;
    while(lo<=hi){
        //cout<<lo<<" "<<hi<<endl;
        int mid = (lo+hi)/2;
        temp = mid;
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(ar[i]-ar[i-1]>mid){
                flag = true;
                break;
            }
            else if(ar[i]-ar[i-1]==mid){
                //k = mid;
                mid--;
            }
            //else k = mid;
        }
        if(flag){
            //cout<<"f "<<lo<<" "<<hi<<endl;
            lo = temp+1;
            //cout<<"f "<<lo<<" "<<hi<<" "<<mid<<endl;
            //getchar();
        }
        else{
            k = temp;
            hi = temp-1;
        }
    }
    return k;
}
int main()
{
    int N=0,T;
    scanf("%d",&T);
    while(++N<=T){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ar[i]);

        int res = binSearch(0,10e9+9);
        printf("Case %d: %d\n",N,res);
    }
    return 0;
}
