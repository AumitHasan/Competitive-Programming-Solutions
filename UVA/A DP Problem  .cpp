#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int main()
{
    string str;
    int idx,T;
    cin>>T;
    while(T--){
        int lxp,lxm,Lp,Lm,rxp,rxm,Rp,Rm;
        lxp=lxm=Lp=Lm=rxp=rxm=Rp=Rm=0;
        //
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(str[i]=='='){
                idx = i;
                break;
            }
        }
        cout<<idx<<endl;
        for(int i=idx-1;i>=0;i--){
            bool flag = false;
            string ch="";
            //cout<<"1"<<endl;
            for(int j=i;j>=0;j--){
                cout<<j<<endl;
                if(str[j]=='x') flag = true;
                //

                if(str[j]=='+'){
                    cout<<1<<endl;
                    if(flag){
                        if(ch.length()==0) ch="1";
                        reverse(ch.begin(),ch.end());
                        lxp += atoi(ch.c_str());
                    }
                    else Lp += atoi(ch.c_str());
                    ch="";
                    i=j;
                    break;
                }
                else if(str[j]=='-'){
                    cout<<2<<endl;
                    if(flag){
                        if(ch.length()==0) ch="1";
                            reverse(ch.begin(),ch.end());
                            lxm += atoi(ch.c_str());
                    }
                    else Lm += atoi(ch.c_str());
                    ch="";
                    i=j;
                    break;
                }
                else if(j==0){
                        cout<<3<<endl;
                    if(str[j]!='x') ch+=str[j];
                    if(flag){
                        if(ch.length()==0) ch="1";
                        reverse(ch.begin(),ch.end());
                        lxp += atoi(ch.c_str());
                    }
                    else Lp += atoi(ch.c_str());
                    ch="";
                    i=j;
                    break;
                }
                else {
                    cout<<4<<endl;
                    ch += str[j];
                }
            }
        }
        cout<<lxp<<" "<<lxm<<" "<<Lp<<" "<<Lm<<endl;
    }
}

