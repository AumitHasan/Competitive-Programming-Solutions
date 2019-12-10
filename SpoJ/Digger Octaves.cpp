#include<bits/stdc++.h>
using namespace std;

void oct(int row,int col,int)
{


    if(row>=0 and row<mx and col>=0 and col<mx) oct(row-1,col);
    if(row>=0 and row<mx and col>=0 and col<mx) oct(row,col+1);
    if(row>=0 and row<mx and col>=0 and col<mx) oct(row+1,col);
    if(row>=0 and row<mx and col>=0 and col<mx) oct(row,col-1);
}
