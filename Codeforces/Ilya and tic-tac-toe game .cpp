#include<bits/stdc++.h>
using namespace std;

int dx[]={0,0,0};
int dy[]={0,1,1};

int da[]={0,1,1};
int db[]={0,0,0};

int dl[]={0,1,1};
int dm[]={0,1,1};

int di[]={0,1,1};
int dj[]={0,-1,-1};

int ar[5][5];

int main()
{
    int o=0,x=0;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            scanf("%c",&ar[i][j]);
            if(ar[i][j]=='x') x++;
            if(ar[i][j]=='o') o++;
        }
    }
    int flag=false;

    if(o==x and o>=2){
        for(int i=1;i<5;i++){
            for(int j=1;j<5;j++){

                int c=0;
                int a = i, b=j;
                for(int k=0;k<3;k++){
                    a = a+dx[k];
                    b = b+dy[k];
                    if(a>0 and a<5 and b>0 and b<5){
                        if(ar[a][b]=='x') c++;
                        else if(ar[a][b]=='o') c--;
                    }
                    else c--;
                }
                if(c==2){
                    cout<<"YES"<<endl;
                    cout<<"a"<<endl;
                    return 0;
                }
                c=0;
                a=i,b=j;
                for(int k=0;k<3;k++){
                    a = a+da[k];
                    b = b+db[k];
                    if(a>0 and a<5 and b>0 and b<5){
                        if(ar[a][b]=='x') c++;
                        else if(ar[a][b]=='o') c--;
                    }
                    else c--;
                }
                if(c==2){
                    cout<<"YES"<<endl;
                    cout<<"b"<<endl;
                    return 0;
                }
                c=0;
                cout<<endl;
                a=i,b=j;
                for(int k=0;k<3;k++){
                    a = a+dl[k];
                    b = b+dm[k];
                    cout<<a<<" "<<b<<endl;
                    if(a>0 and a<5 and b>0 and b<5){
                        if(ar[a][b]=='x') c++;
                        else if(ar[a][b]=='o') c--;
                    }
                    else c--;
                }
                if(c==2){
                    cout<<"YES"<<endl;
                    cout<<"C"<<endl;
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
                c=0;

                a=i,b=j;
                for(int k=0;k<3;k++){
                    a = a+di[k];
                    b = b+dj[k];
                    cout<<a<<" "<<b<<endl;
                    if(a>0 and a<5 and b>0 and b<5){
                        if(ar[a][b]=='x') c++;
                        else if(ar[a][b]=='o') c--;
                    }
                    else c--;
                    cout<<c<<endl;
                }
                if(c==2){
                    cout<<"YES"<<endl;
                    cout<<i<<" "<<j<<endl;
                    cout<<"d"<<endl;
                    return 0;
                }


            }
        }
    }

    cout<<"NO"<<endl;
}
