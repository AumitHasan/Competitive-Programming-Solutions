#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str[][5]={   {' ',' ',' ',' ',' '},{' ','.',',','?','"'},
                      {' ','a','b','c',' '},{' ','d','e','f',' '},
                      {' ','g','h','i',' '},{' ','j','k','l',' '},
                      {' ','m','n','o',' '},{' ','p','q','r','s'},
                      {' ','t','u','v',' '},{' ','w','x','y','z'},
                      {' ',' ',' ',' ',' '} };

    int T;
    cin>>T;
    while(T--)
    {
        int num;
        scanf("%d",&num);
        int n[num],p[num];
        for(int i=0;i<num;i++) scanf("%d",&n[i]);
        for(int i=0;i<num;i++) scanf("%d",&p[i]);

        for(int i=0;i<num;i++)
        {
            printf("%c",str[n[i]][p[i]]);
        }
        printf("\n");
    }

return 0;
}
