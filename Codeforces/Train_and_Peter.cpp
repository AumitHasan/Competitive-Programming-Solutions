#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define mx 100001
#define base 10000011

ll bs[200],has[mx],h[mx],com1,com2,m;

void pre_base()
{
    bs[0]=1;
    for(int i=1;i<200;i++) bs[i] = bs[i-1]*base;
}

bool check_forword(int i,int len,ll com)
{
    ll val;
    if(i==0) val = has[i+len-1];
    else val = has[i+len-1]-(has[i-1]*bs[len]);

    if(com==val) return true;
    else return false;
}

bool check_backword(ll i,ll len,ll com)
{
    //cout<<"hi : "<<h[i]<<endl;
    ll val=0;
    if(i==m) val = h[i-len+1];
    else  val = h[i-len+1]-(h[i+1]*bs[len]);

    //cout<<com<<" "<<val<<endl;

    if(com==val) return true;
    else return false;
}

int main()
{
    pre_base();
    string flag,str,s;
    cin>>flag;
    cin>>s;
    cin>>str;

    ll len = flag.length();
    ll len1 = s.length();
    ll len2 = str.length();

    m = len-1;

    has[0]=flag[0];
    for(int i=1;i<len;i++) has[i] = (has[i-1]*base)+flag[i];


    h[len-1]=flag[len-1];
    for(int i=len-2;i>=0;i--) h[i] = (h[i+1]*base)+flag[i];


    com1=0;
    for(int i=0;i<len1;i++) com1 = (com1*base)+s[i];

    com2=0;
    for(int i=0;i<len2;i++) com2 = (com2*base)+str[i];

    int c=0,cnt=0;
    bool a=false,b=false;


        for(int i=0;i<len;i++)
        {
            if(c==0 && len>=len1 && i<=len-len1){
                if(check_forword(i,len1,com1)==true){ c++; i+=len1-1;}
            }
            else if(c==1 && len>=len2 && i<=len-len2){
                if(check_forword(i,len2,com2)==true){ c++; break;}
            }
        }



    if(c==2) a = true;
    //cout<<"f "<<c<<endl;

    c=0;
    cnt=0;


        for(int i=len-1;i>=0;i--)
        {
            if(c==0 && len>=len1 && i>=len1-1){
                if(check_backword(i,len1,com1)==true){ c++;  i-=len1-1; }
            }
            else if(c==1 && len>=len2 && i>=len2-1){

                if(check_backword(i,len2,com2)==true){ c++; break;}
            }
        }

    //cout<<endl<<"ff "<<c<<endl;

    if(c==2) b = true;


    if(a&b) cout<<"both"<<endl;
    else if(a==true && b==false) cout<<"forward"<<endl;
    else if(a==false && b==true) cout<<"backward"<<endl;
    else cout<<"fantasy"<<endl;


return 0;
}
