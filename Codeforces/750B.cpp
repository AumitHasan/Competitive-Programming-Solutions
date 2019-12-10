#include<bits/stdc++.h>
using namespace std;

int ar[60],mark[60],nw[60];
string str[60],ch[60];
vector<int>v;

int main()
{
    int n,in=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
        cin>>str[i];
    }
    int N,S;


    if(str[0] != "South" or str[n-1] != "North"){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        string ck="South";
        int a = ar[0],b;
        if(a>20000){
            a/=20000;
            b = ar[0]%20000;
            //cout<<b<<endl;
            if(a%2==0){
                N = b;
                S = 20000-N;
            }
            else{
                S = b;
                N = 20000-S;

            }
        }
        else{
            N = ar[0];
            S = 20000-N;
        }
        //cout<<N<<" "<<S<<endl;
        if(N==0) mark[0] = 1;
        else if(S==20000 or S%20000==0) mark[0]=2;

        for(int i=1;i<n;i++){
            if(str[i]=="North"){
                N -= ar[i];
                if(abs(N)%20000==0) mark[i]=1;
                S += ar[i];
            }
            if(str[i]=="South"){
                S -= ar[i];
                if(abs(S)%20000==0) mark[i]=2;
                N += ar[i];
            }
        //cout<<N<<" "<<S<<endl;
        }
        for(int i=1;i<n;i++){
            if(mark[i-1]==1){
                if(str[i]!="South"){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else if(mark[i-1]==2){
                if(str[i]!="North"){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    if(N%20000==0)
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
