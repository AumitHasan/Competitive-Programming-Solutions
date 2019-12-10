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

string F[5009];
int C;

string fibs(string str,string ch)
{
    string new_str;
    int a,b,sum=0,carry=0;
    reverse(str.begin(),str.end());
    reverse(ch.begin(),ch.end());
    int len1=str.length(),len2=ch.length();
    for(int i=0;i<max(len1,len2);i++){
        if(i<len1) sum += str[i]-'0';
        if(i<len2) sum += ch[i]-'0';

        new_str += (sum%10 + '0');
        sum /=  10;
    }
    if(sum>0) new_str += sum+'0';

    reverse(new_str.begin(),new_str.end());
    return new_str;
}
int main()
{
    READ("in.txt");
    WRITE("out.txt");

    F[0] = "0";
    F[1] = "1";
    F[2] = "1";
    for(int i=3;i<=5005;i++){
        F[i] = fibs(F[i-1],F[i-2]);
    }
    int n;
    while(cin >> n){
        cout << "The Fibonacci number for " << n << " is " << F[n] << endl;
    }
    return 0;
}
