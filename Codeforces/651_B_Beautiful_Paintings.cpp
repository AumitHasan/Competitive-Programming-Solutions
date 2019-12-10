#include<bits/stdc++.h>
using namespace std;

int arr[1001],db[1001];

int main()
{
    int n,c=0,mn=0,m=0,res=0;
    bool f=false;
    cin>>n;
    int s[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        arr[s[i]]++;
    }
    int in=-1;
    for(int i=1;i<=1000;i++)
    {
        if(arr[i]==1) c++;
        else if(arr[i]>1){
            db[++in]=arr[i]-1;
            f=true;
            c++;
        }
    }

    //cout<<"C = "<<c<<endl;

    if(c==1) c=0;
    else c--;

    if(f!=false){

        sort(db,db+in);

        //for(int j=0;j<=in;j++) cout<<db[j]<<" ";
        //cout<<endl;

        int ic=0,num=in+1,minm=0,tem=0;

        for(int i=in;i>0;i--)
        {
            if(i!=in){
                if(db[i]==db[i-1]) continue;
            }
            tem = db[i]-ic;
            ic+= db[i]-ic;
            //cout<<"ic = "<<ic<<endl;
            if(i==in)minm = ic;
            else minm = tem;
            //cout<<"minm= "<<minm<<" "<<"num"<<num<<endl;
            res += (num-1)*minm;
            num--;
        }
    }


    //cout<<res<<endl;
    //cout<<c<<endl;
    cout<<res+c<<endl;

return 0;
}
