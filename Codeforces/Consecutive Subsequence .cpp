#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;


int n;
map<int,int>mp;
vector<int>v;

int main()
{
    int m=0,last=-1;
    scanf("%d",&n);
    int ar[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
        mp[ar[i]] = mp[ar[i]-1] + 1;
        if(mp[ar[i]] > m){
            m = mp[ar[i]];
            last = i;
        }
    }
    printf("%d\n",m);

    int val = ar[last];
    for(int i=last;i>0;i--){
        if(ar[i] == val){
            v.push_back(i);
            val--;
        }
    }
    for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);
    return 0;
}
