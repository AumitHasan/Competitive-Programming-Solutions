#include<bits/stdc++.h>

using namespace std;

string color[] = {"red", "yellow", "green", "brown", "blue", "pink", "black"};
int value[] = {1,2,3,4,5,6,7};

int main()
{
    string str;
    int n,r=0,sum=0,mv=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        if(str == color[0]){
            r++;
            sum++;
            mv = max(mv,1);
        }
        else{
            for(int j=0;j<7;j++){
                if(str == color[j]){
                    sum += value[j];
                    mv = max(mv,value[j]);
                }
            }
        }
    }

    if(mv == 1) cout<<1<<endl;
    else cout<<(r*mv + sum)<<endl;

    return 0;
}
