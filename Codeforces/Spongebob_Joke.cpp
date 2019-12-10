#include<bits/stdc++.h>
using namespace std;
int main(){

    long i,j,n,m,cc=0,d=0,dd;
    cin>>n>>m;

    long  a[n],b[m],c[n];

    for(i=0;i<n;i++){

        cin>>a[i];
        c[i]=a[i];
    }
    for(i=0;i<n;i++)
        cin>>b[i];

    sort(a,a+n);
    sort(b,b+m);

    for(i=0;i<n;i++){
    dd=0;
    dd=b[i];

        if(a[i] != b[i]){



            for(j=0;j<n;j++){



                if(dd == c[j])
                    break;
            }


            if(dd == a[j])
                    break;
            cc=1;

        }
    }

    for(i=0;i<n;i++){


        for(j=i+1;j<n;j++){

            if(a[i]==a[j])
            {
                d=1;
                break;
            }

        }

        if(a[i]==a[j])
            break;
    }

    if(cc==1)
        cout<<"Impossible"<<endl;
    else if(d==1)
        cout<<"Ambiguity"<<endl;
    else if(d==0){
        cout<<"Possible"<<endl;
        for(i=0;i<n;i++){
            cout<<c[i]<<" ";

       }
       cout<<endl;

    }



return 0;
}
