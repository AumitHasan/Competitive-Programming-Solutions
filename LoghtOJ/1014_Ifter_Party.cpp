#include<bits/stdc++.h>
using namespace std;

/*bool com(int x,int y){

    return x>y;
}*/
int main(){

    int q,t,N=0,n,p,l,i;
    cin>>t;
    while(++N <=t)
    {
        cin>>p>>l;
        vector <int> v;
        v.clear();

        q=0;
        q=p-l;

        if(q<=l){
            printf("Case %d: impossible\n",N);
            continue;
        }


        for(i=1;i<=sqrt(q);i++)
        {
            if(q%i == 0){
                v.push_back(i);
                if(i*i != q) v.push_back(q/i);
            }
        }

        //sort(v.begin(),v.end(),com);
        sort(v.begin(),v.end());
        printf("Case %d:",N);
        for(i=0;i<v.size();i++)
        {
            if(v[i]>l)
                printf(" %d",v[i]);
        }
        printf("\n");

    }

return 0;
}
