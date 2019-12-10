#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
//
int gx[] = {-1, -2, -2, -1, 1, 2, 2,  1};
int gy[] = {-2, -1, 1,   2, 2, 1, -1, -2};

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
#define pii acos(-1.0)

#define mx 100007

bool opp[10][10];
string ch[8];

bool ck(int x,int y)
{
    if(x>=0 & x<8 && y>=0 && y<8) return 1;
    return 0;
}
bool pawn(int x,int y)
{
    if(ck(x-1,y-1) && opp[x-1][y-1]) return 1;
    if(ck(x-1,y+1) && opp[x-1][y+1]) return 1;
    return 0;
}
bool hati(int x,int y)
{
    int e,f;
    //1
    for(int i=1;i<9;i++){
        e = x-i; f = y-i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //2
    for(int i=1;i<9;i++){
        e = x-i; f = y+i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //3
    for(int i=1;i<9;i++){
        e = x+i; f = y-i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //4
    for(int i=1;i<9;i++){
        e = x+i; f = y+i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    return 0;
}
bool board(int x,int y)
{
    int e,f;
    //1
    for(int i=1;i<9;i++){
        e = x-i; f = y;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //2
    for(int i=1;i<9;i++){
        e = x+i; f = y;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //3
    for(int i=1;i<9;i++){
        e = x; f = y-i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    //4
    for(int i=1;i<9;i++){
        e = x; f = y+i;
        if(ck(e,f)){
            if(ch[e][f] != '.'){
                if(opp[e][f]) return 1;
                break;
            }
        }
    }
    return 0;
}
bool gora(int x,int y)
{
    for(int i=0;i<8;i++){
        int tx = x + gx[i];
        int ty = y + gy[i];
        if(ck(tx,ty) && opp[tx][ty]) return 1;
    }
    return 0;
}
bool king(int x,int y)
{
    for(int i=0;i<8;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(ck(tx,ty) && opp[tx][ty]) return 1;
    }
    return 0;
}
int main()
{
    bool flag = false;
    string pos;
    for(int i=0;i<8;i++) cin>>ch[i];
    cin>>pos;
    int r = pos[1] - '0';
    int cl = pos[0] - 'a';
    opp[8-r][cl] = true;
    //cout<<r<<" "<<8-r<<" "<<cl<<endl;
    //
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(ch[i][j]=='p'){
                flag |= pawn(i,j);
            }
            else if(ch[i][j]=='c'){
                flag |= gora(i,j);
            }
            else if(ch[i][j]=='b'){
                flag |= hati(i,j);
            }
            else if(ch[i][j]=='r'){
                flag |= hati(i,j);
                flag |= board(i,j);
            }
            else if(ch[i][j]=='k'){
                flag |= king(i,j);
            }
            else if(ch[i][j]=='t'){
                flag |= board(i,j);
            }
        }
    }
    if(flag) cout<<"Sim"<<endl;
    else cout<<"Nao"<<endl;

    return 0;
}
