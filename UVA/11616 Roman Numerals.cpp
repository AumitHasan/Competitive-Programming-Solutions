#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    vector<pair<int,string> >v;
    v.push_back(make_pair(1000,"M"));
    v.push_back(make_pair(900,"CM"));
    v.push_back(make_pair(500,"D"));
    v.push_back(make_pair(400,"CD"));
    v.push_back(make_pair(100,"C"));
    v.push_back(make_pair(90,"XC"));
    v.push_back(make_pair(50,"L"));
    v.push_back(make_pair(40,"XL"));
    v.push_back(make_pair(10,"X"));
    v.push_back(make_pair(9,"IX"));
    v.push_back(make_pair(5,"V"));
    v.push_back(make_pair(4,"IV"));
    v.push_back(make_pair(1,"I"));
    map<string,int>mp;
    mp["I"]=1;mp["V"]=5;mp["X"]=10;mp["L"]=50;mp["C"]=100;mp["D"]=500;mp["M"]=1000;
    string s;
    while(cin>>s){
        string rs;
        if(s[0]<60){
            int n=0,d;
            for(int i=0;i<s.size();i++){
                d=s[i]-48;
                n = (n*10)+d;
            }
            //cout<<n<<endl;
            for(int i=0;i<v.size() and n>0;i++){
                int a=n/v[i].first;
                //cout<<i<<" "<<a<<endl;
                if(a>=1){
                    n-=a*v[i].first;
                    for(int j=1;j<=a;j++) rs+=v[i].second;
                }
            }
            cout<<rs<<endl;
        }
        else{
            int n=0,x,y;
            string ch,a,b;
            for(int i=s.size()-1;i>=0;i--){
                ch=s[i];
                a=s[i]; b=s[i-1];
                x=mp[a]; y=mp[b];
                if(i==0){ n+=mp[ch]; break;}
                if(x>y){
                    string str,ss;//= s.substr(i-1,i+1);
                    //m=s[i-1]; mm=s[i];
                    //str.append(m); str.append(mm);
                    str.push_back(s[i-1]);
                    ss.push_back(s[i]);
                    //cout<<str<<endl;
                    n+=mp[ss]-mp[str];
                    i--;
                }else n+=mp[ch];
            }
            printf("%d\n",n);
        }

    }
    return 0;
}
