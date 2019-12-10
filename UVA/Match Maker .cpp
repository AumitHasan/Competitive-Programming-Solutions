#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define base 30000007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

string str,pt,a,b,c,add="11";
int ck,x,y,z,ans;

int prm[10],ar[]={1,2,3,4};


int main()
{
    IO;

    bool flag = 1;
    int test=1,c=0,idx,len;
    while(1){
        cin>>str;
        if(str=="QUIT") break;
        if(str=="END"){
            test++; c=0;
            flag = 1; continue;
        }
        //
        str = add + str + add;
        if(flag) len = str.length();
        int tmp = str.length();
        //
        if(flag){
            pt = str;
            ck = 0;
            for(int i=0;i<str.length();i++){
                if(str[i]=='*'){
                    x = i; y = len - i - 1;
                    a = str.substr(0,i);
                    b = str.substr(i+1,len-1);
                    ck=1; break;
                }
                if(str[i]=='#'){
                    x = i; y = len - i - 1;
                    a = str.substr(0,i);
                    b = str.substr(i+1,len-1);
                    //cout<<a<<" "<<b<<" "<<x<<" "<<y<<endl;
                    ck=2; break;
                }
            }
            flag = 0;
        }
        else{
            c++;
            if(!ck){
                if(pt==str){
                    cout<<test<<"."<<c<<". match"<<endl;
                }
                else cout<<test<<"."<<c<<". not"<<endl;
            }
            else if(ck==1){ //*
                if(str.length() >= len-1){
                    int yy = tmp - y; z = tmp - 1;
                    //cout<<str.substr(0,x)<<" "<<str.substr(y,z)<<endl;
                    if(str.substr(0,x)==a && str.substr(yy,z)==b && (yy-x-1)%2==1){
                        cout<<test<<"."<<c<<". match"<<endl;
                    }
                    else cout<<test<<"."<<c<<". not"<<endl;
                }
                else cout<<test<<"."<<c<<". not"<<endl;

            }
            else if(ck==2){ //#
                if(str.length() >= len){
                    int yy = tmp - y; z = tmp - 1;
                    //cout<<tmp<<" "<<y<<" "<<z<<endl;
                    //cout<<str.substr(0,x)<<" "<<str.substr(y,z)<<endl;
                    if(str.substr(0,x)==a && str.substr(yy,z)==b && (yy-x-1)%2==0){
                        cout<<test<<"."<<c<<". match"<<endl;
                    }
                    else cout<<test<<"."<<c<<". not"<<endl;
                }
                else cout<<test<<"."<<c<<". not"<<endl;
            }
        }
    }
}

