#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define mx 100007
#define mod 1000000007
#define base 10000007
#define ll long long int
#define llu unsigned ll
#define umap unordered_map
#define mem(a,b) memset(a,b,sizeof(a))
#define pr pair<int,int>
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int ar[mx];

int main()
{
    string str,ch;
    cin>>str;
    int len = str.length();
    for(int i=0;i<len;i++){
        ar[i] = str[i]-'0';
    }
    while(1){
        int num=0;
        for(int i=0;i<str.length();i++){
            num += str[i] - '0';
            num %= 7;
        }
        if(str[0]!='0' && num==0){
            cout<<str<<endl;
            return 0;
        }
        //
        ch = "";
        int val,rem=1,len = str.length();
        for(int i=len-1;i>=0;i--){
            val = str[i]-'0' + rem;
            rem = val/10;
            val = val % 10;
            ch += char (val + '0');
            cout<<ch<<endl;
            getchar();
        }
        if(rem>0) ch += char (rem + '0');
        reverse(ch.begin(),ch.end());
        str = ch;
    }
}
