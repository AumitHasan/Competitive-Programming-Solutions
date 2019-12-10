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


char ch[10][10];

int main()
{
    bool flag = false;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++) cin>>ch[i][j];
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){

            if(ch[i][j]=='X'){

                for(int ix=0;ix<8;ix++){

                    int x = i,y=j;
                    int a=0,b=0,c=0;

                    for(int k=0;k<4;k++){
                        x = x+d8x[ix];
                        y = y+d8y[ix];

                        if(x>=0 && x<10 && y>=0 && y<10){
                            if(ch[x][y]=='X') a++;
                            else if(ch[x][y]=='O') b++;
                            else c++;
                        }
                    }
                    if(a==3 && c==1) flag = true;
                }//
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
