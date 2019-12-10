#include<bits/stdc++.h>
using namespace std;

int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};
#define ll long long int
#define llu unsigned long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pii 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 1007
#define int_map map<int,int>
#define v_map map<int,vector<int> >
#define long_map map<long long,long long>
#define IO ios::sync_with_stdio(false)
#define inputline(a) getline(cin,a)
#define INF (1LL<<31)-1
//int gcd(int x,int y){return (y==0)?x:gcd(y,x%y);};
#define gcd(a,b) __gcd(a,b)



int main()
{
    int n,T;
    cin>>T;
    while(T--){
        string str,ch;
        scanf("%d",&n);
        cin>>str;
        cin>>ch;

        bool flag = false ;
        for(int i=0;i<n;i++){
            if(str[i]=='*' && ch[i]=='*') flag = true;
        }

        int c=0,a=0,b=0;

        if(flag){
            c++;
            for(int i=0;i<n-1;i++){
                if(str[i]=='*') a = 1;
                if(ch[i]=='*') b = 1;

                if(str[i+1]=='*' && a==1){
                    c++;
                    a=b=0;
                }
                else if(ch[i+1]=='*' && b==1){
                    c++;
                    a=b=0;
                }
            }
            cout<<c<<endl;
        }
        else{
            a=b=0;
            c=1;
            for(int i=0;i<n-1;i++){
                if(str[i]=='*') a = 1;
                if(ch[i]=='*') b = 1;

                if(str[i+1]=='*' && a==1){
                    c++;
                    a=b=0;
                }
                else if(ch[i+1]=='*' && b==1){
                    c++;
                    a=b=0;
                }
            }
            int res = c;

            a=b=0;
            c = 0;
            for(int i=0;i<n-1;i++){
                if(str[i]=='*') a = 1;
                if(ch[i]=='*') b = 1;

                if((a==1 || b==1) && (str[i+1]=='*' || ch[i+1]=='*')){
                    c++;
                    a=b=0;
                }
            }
            //cout<<"  mid "<<res<<" "<<c<<endl;
            cout<<min(c,res)<<endl;
        }

        //cout<<min(c,res)<<endl;
    }
    return 0;
}
