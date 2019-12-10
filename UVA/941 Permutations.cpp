#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll fact[21];
    fact[1]=1;
    for(int i=2;i<=20;i++) fact[i]=fact[i-1]*i;
    //cout<<fact[20];
    ll t,n;
    string s,ch,rs;
    scanf("%lld",&t);
    while(t--){
        s.clear();
        ch.clear();
        rs.clear();
        cin>>ch;
        int len = ch.length();
        sort(ch.begin(),ch.end());
        //cout<<ch<<endl;
        int c=0;
        scanf("%lld",&n);

        if(n<7){
            int c=0;
            do{
                ++c;
                if(c==n+1){
                    cout<<ch<<endl;
                    break;
                }
            }while(next_permutation(ch.begin(),ch.end()));
        }
        else{
            ll a;

            ll f=fact[len];
            for(int i=1;i<=len;i++){
                if(n<fact[i]){
                    a=i+1;
                    break;
                }
            }
            //cout<<a<<" "<<fact[a]<<endl;
            if(n==fact[len]) a--;
            for(int i=0;i<len-a;i++) rs+=ch[i];
            for(int i=len-a;i>0 and i<len;i++) s+=ch[i];
            if(s.length()>0) ch=s;
            //cout<<ch<<endl;
            //cout<<ch<<endl<<endl;
            /*if(fact[a]%n==0){
                rs+=ch[0];
                for(int i=ch.length()-1;i>0;i--) rs+=ch[i];
                cout<<rs<<endl;
                continue;
            }*/
            //cout<<"n:"<<n<<endl;
            for(int i=0;i<len-3;i++){
                if(n<=6) break;
                ll x = fact[--a];
                ll a = n/x;
                n=n%x;
                //cout<<i<<" n:"<<n<<endl;


               // cout<<"stp: "<<x<<" "<<a<<" "<<n<<endl;
                if(n%x!=0){
                    rs+=ch[a];
                    s.clear();
                    for(int j=0;j<ch.length();j++){
                        if(j==a) continue;
                        s+=ch[j];
                    }
                    ch=s;
                    //cout<<rs<<endl;
                }
                else{
                    rs+=ch[0];
                    s.clear();
                    for(int j=ch.length()-1;j>0;j--){
                        rs+=ch[j];
                    }
                    c=1;
                    break;
                }
               // cout<<"s: "<<rs<<" "<<s<<endl;
                //getchar();
                //cout<<rs<<endl;
            }
            //cout<<rs<<endl;
            //return 0;
            if(ch.length()>0 and c==0){
                int cnt=0;
                do{
                    if(++cnt==n+1) break;
                }while(next_permutation(ch.begin(),ch.end()));
                cout<<rs+ch<<endl;
            }
            else cout<<rs<<endl;

        }
    }
}
