#include<bits/stdc++.h>
using namespace std;

int ar[105];

int main()
{
    //freopen("out.txt","w",stdout);

    string str;
    int T;
    cin>>T;

    cin.ignore();
    while(T--){
        int gcd=0,m,in=-1;
        getline(cin,str);
        stringstream ss(str);
        while(ss){
            ss>>ar[++in];
            //cout<<ar[in]<<" ";
        }
        //cout<<endl<<in<<endl;;
        m = in;

        //gcd = __gcd(ar[0],ar[1]);
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j) continue;
                gcd = max(gcd, __gcd(ar[i],ar[j]));
            }
        }
        cout<<gcd<<endl;
    }
}
