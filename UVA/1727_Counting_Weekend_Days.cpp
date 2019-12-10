#include<bits/stdc++.h>
using namespace std;

string day[]={"a","FRI","SAT","SUN","MON","TUE","WED","THU"};
string month[]={"a","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
int dm[]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int d,c=0,m;
        string a,b;
        cin>>a>>b;
        for(int i=1;i<8;i++)
            if(day[i]==b) d=i;
        for(int i=1;i<13;i++)
            if(month[i]==a) m=i;

        m = dm[m];
        for(int i=1;i<=m;i++)
        {
            if(d%7==1 or d%7==2) c++;
            ++d;
        }
        printf("%d\n",c);
    }
return 0;
}
