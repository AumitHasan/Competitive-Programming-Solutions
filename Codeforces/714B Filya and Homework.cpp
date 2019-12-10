#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c=0,a=-1,n,sum=0,j=-1;
    cin>>n;
    int ar[n],com[3];
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    sort(ar,ar+n);
    for(int i=0;i<n;i++){
        if(ar[i]!=a){
            c++;
            a=ar[i];
        }
    }
    //cout<<c<<endl;
    if(c<=2){
        cout<<"YES"<<endl;
        return 0;
    }
    else if(c==3){
        a=-1;
        for(int i=0;i<n;i++){
            if(ar[i]!=a){
                com[++j] = ar[i];
                a=ar[i];
            }
        }
        //cout<<"fuc"<<endl;
        int r = com[1]-com[0];
        int rr = com[2]-com[1];
        if(r==rr) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else cout<<"NO"<<endl;
   /* int mn = ar[0];
    int mx = ar[n-1];
    int b = mx-mn-1;
    if(b%2!=0){
        int x = b/2+1;
        int dif = x-mn;
        int num = mn+dif;
        for(int i=0;i<n;i++){
            if(ar[i]==num) continue;
            if(ar[i]-dif!=num or ar[i]+dif!=num){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }
    cout<<"YES"<<endl; */

return 0;
}
