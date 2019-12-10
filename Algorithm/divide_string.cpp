#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

int main()
{



    char gt[100];
    //gets(gt);
    while(gets(gt) && strlen(gt))
    {
        char *sp;
        string a,b;
        sp = strtok(gt," ");
        a = sp;
        sp = strtok(NULL," ");
        b = sp;
        cout<<a<<" "<<b<<endl;
    }

return 0;
}
