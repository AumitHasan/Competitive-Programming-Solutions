#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define mx 100007

bool flag[mx];
vector<int>prime;

void seive()
{
    prime.push_back(2);
    for(int i=3;i*i<mx;i+=2){
        if(!flag[i]){
            prime.push_back(i);
            for(int j=i*i;j<mx;j+=2*i) flag[j] = true;
        }
    }
    for(int i=317;i<mx;i+=2){
        if(!flag[i]) prime.push_back(i);
    }
}
int eularPhi(int n)
{
    int res = n;
    for(int i=0; i < prime.size() && prime[i] <= sqrt(n); i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                n /= prime[i];
            }
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if(n != 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}
int main()
{
    seive();
    //
    cout<<eularPhi(9)<<endl;
}
