#include<bits/stdc++.h>
using namespace std;

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
int d8x[]={-1,-1,0,1,1,1,0,-1};
int d8y[]={0,1,1,1,0,-1,-1,-1};


int main()
{
    ll T,N=0,b,num;
    scanf("%lld",&T);
    while(++N<=T){
        string ch="\0";
        cin>>ch;
        cin>>b;
        ll len = ch.length(),s=0;
        if(ch[0]=='-'){
            s = 1;
        }
        //cout<<len<<" "<<s<<endl;
        num=0;
        if(b<0) b *= -1;
        while(s<len){
            if(b>num){
                num = (num*10)+(ch[s]-48);
                s++;
            }
            else{
                //cout<<num<<" ";
                num = num%b;
                //cout<<num<<endl;
            }
            //cout<<"n: "<<num<<endl;
        }
        num = num%b;
        //cout<<num<<" "<<b<<endl;
        if(num==0) printf("Case %lld: divisible\n",N);
        else printf("Case %lld: not divisible\n",N);

    }
}
