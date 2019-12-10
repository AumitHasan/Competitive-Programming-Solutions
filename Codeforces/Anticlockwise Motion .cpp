#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll start[1000000],wall,fast,last,s,e,a,b,x,y,row,col;

void process()
{
    start[1] = 2;
    for(ll i=2;i<=17000;i++){
        start[i] = start[i-1] + (i-1)*8 ;
    }
    //cout<<start[17000]<<endl;
    //for(ll i = 1700-10;i<=1700;i++) cout<<start[i]<<endl;
}
void S()
{
    if(fast==s){
        a = row; b = col; return;
    }
    for(int i=1;i<=wall-2;i++){
        fast++;
        row++;
        if(fast==s){
            a = row; b = col; return;
        }
        //cout<<row<<" "<<col<<endl;
    }
    for(int i=1;i<wall;i++){
        fast++;
        col++;
        if(fast==s){
            a = row; b = col; return ;
        }
    }
    for(int i=1;i<wall;i++){
        fast++;
        row--;
        if(fast==s){
            a = row; b = col; return;
        }
    }
    for(int i=1;i<wall;i++){
        fast++;
        col--;
        if(fast==s){
            a = row; b = col; return;
        }
    }
}
void E()
{
    if(fast==e){
        x = row; y = col; return;
    }
    for(int i=1;i<=wall-2;i++){
        fast++;
        row++;
        if(fast==e){
            x = row; y = col; return;
        }
    }
    for(int i=1;i<wall;i++){
        fast++;
        col++;
        if(fast==e){
            x = row; y = col; return ;
        }
    }
    for(int i=1;i<wall;i++){
        fast++;
        row--;
        if(fast==e){
            x = row; y = col; return;
        }
    }
    for(int i=1;i<wall;i++){
        fast++;
        col--;
        if(fast==e){
            x = row; y = col; return;
        }
    }
}
int main()
{
    process();


    cin>>s>>e;

    for(ll i=17000;i>=1;i--){
        if(s>=start[i]){
            //cout<<"s "<<i<<endl;
            row = i;
            fast = start[i];
            wall = i*2 + 1;
            last = start[i+1] - 1;
            break;
        }
    }
    col = -row;
    row = -(row-1);
    //cout<<fast<<endl;
    //cout<<row<<" "<<col<<endl;
    if(s==1) a=0,b=0;
    else S();
    //cout<<a<<" "<<b<<endl<<endl;


    for(int i=17000;i>=1;i--){
        if(e>=start[i]){
            row = i;
            fast = start[i];
            wall = i*2 + 1;
            last = start[i+1] - 1;
            break;
        }
    }
    col = -row;
    row = -(row-1);
    if(e==1) x=0,y=0;
    else E();
    //cout<<a<<" "<<b<<endl;
    //cout<<x<<" "<<y<<endl;

    if(a>=0 && x>=0) row = abs(a-x);
    else if(a<0 && x<0) row = abs(a-x);
    else row = abs(abs(a) + abs(x));

    if(b>=0 && y>=0) col = abs(b-y);
    else if(b<0 && y<0) col = abs(b-y);
    else col = abs(abs(b) + abs(y));

    //if(row==0) row = 1;
    //if(col==0) col = 1;
    //cout<<endl<<row<<" "<<col<<endl;
    //cout<<(row*col)<<endl;
    cout<<row+col<<endl;
}
