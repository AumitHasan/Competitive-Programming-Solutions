#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T,N=0;
    cin>>T;
    while(++N <=T)
    {
        long n;
        string s;
        cin>>n>>s;

        if(s=="Alice")
        {
            if(n%3==1)
                printf("Case %d: Bob\n",N);
            else
                printf("Case %d: Alice\n",N);

        }else{

            if(n%3==1 || n%3==2)
                printf("Case %d: Bob\n",N);
            else
                printf("Case %d: Alice\n",N);

        }
    }

return 0;
}
