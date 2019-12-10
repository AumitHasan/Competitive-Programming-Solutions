#include<bits/stdc++.h>
using namespace std;

int found,contain[6];

void call(int n)
{
    if(found){
        //cout<<"xx: "<<found<<endl;
        return ;
    }

    if(n==0){
        int c=0;
        for(int j=1;j<=5;j++){
           // cout<<contain[j]<<" ";
            if(contain[j]>0) c++;
        }
        //cout<<endl;
        if(c==5){
           // cout<<"found"<<endl;
            found = 1;
            //return true;
        }
        return ;
    }


    if(contain[n]==0){
        //cout<<n<<endl;
        for(int i=1;i<=n/2;i++){

            int j = n-i;
            if(i!=j and contain[i]>0 and contain[j]>0){
                contain[i]--;
                contain[j]--;
                contain[n] = 1;

                //cout<<contain[i]<<" "<<contain[j]<<" "<<n<<endl;
                call(n-1);

                contain[n] = 0;

                contain[i]++;
                contain[j]++;
            }
            else if(i==j and contain[i]>2){
                contain[i] -= 2;
                contain[n] = 1;

                //cout<<contain[i]<<" "<<contain[j]<<" "<<n<<endl;
                call(n-1);

                contain[n] = 0;
                contain[i] += 2;
            }

        }
    }
    else{
        //cout<<"n: "<<n<<endl;
        call(n-1);
    }

    //return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){

        found = 0;
        memset(contain,0,sizeof(contain));

        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            contain[s[i]-64]++;
            //p[s[i]-64]++;
        }

        call(5);
        int res = found;

        if(res == 0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
