#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num,n,in=-1,a=0;
    string s;
    cin>>n;
    cin>>s;
    if(n==0 and s[0]=='0' and s.length()==1){
        cout<<"OK"<<endl;
        return 0;
    }
    if(s[0]=='0'){
        cout<<"WRONG_ANSWER"<<endl;
        //else cout<<"OK"<<endl;
        return 0;
    }

    num = n;
    int ar[100];
    while(n>0){
        ar[++in] = n%10;
        n/=10;
    }

    sort(ar,ar+in+1);
    //for(int i=0;i<=in;i++) cout<<ar[i]<<" ";
//cout<<endl;
    int x = 0;
    for(int i=0;i<=in;i++){
        if(ar[i]>0){
            x = i;
            break;
        }
    }

    int sum =ar[x];

    for(int i=0;i<=in;i++){
        if(i==x) continue;
        sum = (sum*10)+ar[i];
    }
    //cout<<sum<<endl;
    string nw;
    stringstream ss;
    ss << sum;
    nw = ss.str();

    //string str = to_string(sum);
    if(nw.compare(s)==0) cout<<"OK"<<endl;
    else cout<<"WRONG_ANSWER"<<endl;

    return 0;
}
