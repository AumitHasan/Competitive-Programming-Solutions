
#include<iostream>
using namespace std;
#include<stdio.h>

int main(){

    float h,u,d,f,i,dis,climb,slide,c=1,x;
    int y;
    while(scanf("%f %f %f %f",&h,&u,&d,&f)==4){

    if(h==0)
        break;
    c=1;
    x=y=0;

    slide=u-d;
    //cout<<slide<<endl;
    f=u*(f/100);
    //printf("%.2f\n",f);
    //cout<<f<<endl;
    climb=u;
    dis=u;
    while(1){

       dis-=f;
       climb=slide+dis;
       slide=climb-d;

       //cout<<dis<<" "<<climb<<" "<<slide<<endl;


        c++;

        if(slide<0 || climb>=h)
            break;

      printf("%.2f   %.2f    %.2f      %f\n",dis,climb,slide,c);

        if(dis<0)
        {
            x=slide/d;
            y=x;
            if(y<x)
                y++;
            break;
        }



    }
    c+=y;
    //cout<<c<<climb;
    if(climb>=h)
        cout<<"success on day "<<c<<endl;
    else
        cout<<"failure on day "<<c<<endl;

    dis=climb=slide=0;

   }


return 0;
}


