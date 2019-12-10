#include<bits/stdc++.h>
using namespace std;
#define  mx 9

int chess[mx+1][mx+1],rw[mx+1][mx+1],cl[mx+1][mx+1],found,box[4][4][10],in,mark[mx][mx];
string ch;

void suduku(int row,int col)
{
    if(found) return ;

    if(row>=mx){
        for(int j=0;j<mx;j++){
            for(int k=0;k<mx;k++) printf("%d ",chess[j][k]);
            cout<<endl;
        }
        found = 1;
        return ;
    }

    for(int i=1;i<=mx;i++){

        int x = row/3;
        int y = col/3;

        if(!rw[row][i] and !cl[col][i] and !box[x][y][i]){

            rw[row][i] = cl[col][i] = box[x][y][i] = 1;
            chess[row][col] = i;

            if(col==mx-1) suduku(row+1,0);
            else suduku(row,col+1);

            chess[row][col] = 0;
            rw[row][i] = cl[col][i] = box[x][y][i] = 0;

        }
    }

}
int main()
{

    suduku(0,0);
}
