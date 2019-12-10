#include<bits/stdc++.h>
using namespace std;
#define mx 100000
#define lim 10000020331
#define idx 141425
typedef unsigned long long int ll;


int sum[idx];
int n,pillo,m,pos;


int srch(int val,int right)
{
    if(val==0) return 0;
    int lo=1,hi=141423,ans=0;

    while(lo<hi){

        int mid = (lo+hi)/2;

         //sum[left] + (sum[left-1]-sum[left-1-right]);

        int last = mid-1-right;
        if(last<0) last = 0;

        //int n = sum[mid] + (sum[mid-1]+sum[last]);

        ll n = (mid*(mid+1))/2 + ((mid*(mid-1))/2 + (last*(last-1))/2);

        if(n==val) return mid;

        ans = lo;

        if(n>val) hi = mid-1;
        else if(n<val) lo = mid+1;

    }
    return ans;
}
int main()
{
    for(int i=1;;i++){
        //if(sum[i]>=lim) break;
        if(i>=141424) break;
        sum[i] = sum[i-1]+i;
    }

    cin>>n>>pillo>>pos;
    int res;

    if(pos==1 or pos==n){

        ll a = (n*(n+1))/2;

        pillo -= n;
        //cout<<pillo<<endl;
        if(pillo>=a){
            //cout<<" l ";
            res = n+1;
            pillo -= a;
            //if(pillo>a) pillo -= a;
            //else pillo = 0;
            res += (pillo/n);
            cout<<res<<endl;
            return 0;
        }
        else{
            //cout<<" x ";
            //res = 0;
            //for(int i=1;i<)
            //res = srch(pillo,0)+1;
            for(int i=0;;i++){
                if(sum[i]==pillo){
                    cout<<i+1<<endl;
                    return 0;
                }
                else if(sum[i]>pillo){
                    cout<<i<<endl;
                    return 0;
                }
            }
        }
        //cout<<res<<endl;
    }
    else{
        pillo -= n;
        //cout<<"ksjfL";
        int left = max(pos,n-pos);
        int right = min(pos,n-pos);
        //cout<<endl<<left<< " "<<right<<endl;
        //cout<<"  j ";
        int last = left-1-right;
        if(last<0) last=0;
        //int a = sum[left] + (sum[left-1]-sum[last]);
        ll a = (left*(left+1))/2 + ( (left*(left-1))/2 - (last*(last+1))/2 );
        //cout<<a<<endl;
        //cout<"  j";
        if(pillo>=a){
                //cout<<" new ";
            pillo -= a;
            if(pillo>0) left += pillo/n;
            cout<<left+1<<endl;
        }
        else{
            //pillo -= n;
        //cout<<" fkda ";
            res = srch(pillo,right) + 1;

            cout<<res <<endl;
        }
    }
}
