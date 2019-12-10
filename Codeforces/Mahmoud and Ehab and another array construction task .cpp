#include <iostream>
#include <vector>
#include <set>
#include<stdio.h>
using namespace std;

#define mx 2000005

bool erg[2000005],prime[2000005];
vector<int>Div[2000005];
set<int>st;


int main()
{
    for(int i=2;i<2000005;i++){
        st.insert(i);
        if(!prime[i]){
            for(int j=i;j<2000005;j+=i){
                Div[j].push_back(i);
                prime[i] = 1;
            }
        }
    }
    //
    int n,num,cur;

    scanf("%d",&n);

    bool flag = false;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        int cur = *st.begin();

        if(!flag){
            cur = *st.lower_bound(num);
            if(cur != num) flag = true;
        }
        printf("%d ",cur);

        for(int x : Div[cur]){
            for(int j=x;j<2000005;j+=x){
                if(!erg[j]){
                    st.erase(j);
                    erg[j] = 1;
                }
            }
        }
    }

}
