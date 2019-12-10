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
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int len = str.length();
        if(len==1){
            if(str[0]=='s') cout<<"snakes"<<endl;
            else cout<<"mongooses"<<endl;
            continue;
        }
        else{
            if(str[0]=='m' && str[1]=='s'){
                str[1] = 'x';
            }
            for(int i=1;i<len;i++){
                if(str[i]=='m' && str[i-1]=='s') str[i-1] = 'x';
                else if(i<len-1 && str[i]=='m' && str[i+1]=='s') str[i+1] = 'x';
            }
            int s=0,m=0;
            for(int i=0;i<len;i++){
                if(str[i]=='s') s++;
                else if(str[i]=='m') m++;
            }
            if(s>m) cout<<"snakes"<<endl;
            else if(s<m) cout<<"mongooses"<<endl;
            else cout<<"tie"<<endl;
        }
    }

}
