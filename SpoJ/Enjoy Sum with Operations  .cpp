#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int dx[] = { 0, 0, -1,    1, -1, -1,  1, 1};
int dy[] = {-1, 1,  0,    0, -1,  1, -1, 1};

typedef long long int           ll;
typedef unsigned long long int  llu;
typedef pair<int,int>           pr;

#define     pf(a)                   cout<<a<<endl
#define     sci(a)                  scanf("%d",&a)
#define     scii(a, b)              scanf("%d %d",&a, &b)
#define     sciii(a, b, c)           scanf("%d %d %d",&a, &b, &c)
#define     scl(a)                  scanf("%lld", &a)
#define     scll(a, b)              scanf("%lld %lld", &a, &b)
#define     sclll(a, b, c)          scanf("%lld %lld %lld", &a, &b, &c)
#define     MAX3(a,b,c)              max(a,max(b,c))
#define     MAX4(a,b,c,d)            max(max(a,b),max(c,d))
#define     umap                    unordered_map
#define     mem(a,b)                memset(a,b,sizeof(a))
#define     IO                      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     READ(f)                 freopen(f,"r",stdin)
#define     WRITE(f)                freopen(f,"w",stdout)


#define     mod                     1000000007
#define     base                    10000007
#define     eps                     1e-9
#define     INF                     1llu<<61
#define     inf                     1<<29
#define     PI                      acos(-1.0) //3.14159.....


#define     mx                      100028

////
ll sum[mx];
int n,q,pw[mx],ar[mx];
string ch;

int tree[mx][100];
vector<int>vec;


void update(int pos,int x,int n,int idx)
{
    //cout<<idx<<" "<<x<<" "<<pos<<endl;
    while(idx<=n){
        //cout<<"val: "<<tree[idx][pos]<<" ";
        tree[idx][pos] += x;
        //cout<<" after "<<tree[idx][pos]<<endl;
        idx += idx & (-idx);
        //if(idx<10) cout<<"i: "<<idx<<endl;
    }
}
int query(int idx,int pos)
{
    int sum = 0;
    while(idx>0){
        sum += tree[idx][pos];
        idx -= idx & (-idx);
    }
    return sum;
}
void make_tree(int num,int pos)
{
    vec.clear();
    int tmp = ar[pos];


    //if(tmp==0) vec.push_back(0);
    while(tmp){
        vec.push_back(tmp%2);
        tmp/=2;
    }
    //reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        if(vec[i]) update(i,-vec[i],n,pos);
        //update(1,1,n,pos,i,vec[i]);
        //cout<<i<<" "<<vec[i]<<endl;
    }

    vec.clear();
    ar[pos] = num;
    //cout<<"F"<<endl;
    //if(num==0) vec.push_back(0);
    while(num){
        vec.push_back(num%2);
        num/=2;
    }

    for(int i=0;i<vec.size();i++) update(i,vec[i],n,pos); //update(1,1,n,pos,i,0);
    //cout<<endl;
//    for(int i=1;i<=10;i++) cout<<tree[i][1]<<" ";
//    cout<<endl;
}
llu clc(int l,int r,int type)
{
    int one,zero,ttl,lo,hi;
    ll res = 0;

    //cout<<endl;
    for(int i=0;i<=28;i++){
        one = query(r,i) - query(l-1,i); //query(1,1,n,l,r,i,1);
        //cout<<"x: "<<i+1<<" "<<one<<endl;
        //zero = query(1,1,n,l,r,i,0);
        zero = (r-l+1) - one;
        ttl = one + zero;
        //cout<<zero<<" x "<<one<<endl;

        if(!one) continue;
        //cout<<i<<" "<<one<<" "<<zero<<endl;

        if(type==1){//or
            lo = ttl - one;
            hi = lo + one - 1;
            if(lo>hi || lo<=0) continue;
            //cout<<lo<<" "<<hi<<endl;
            res += llu (pw[i] * (sum[hi] - sum[lo-1]));
        }
        else if(type==2){//and
            res += llu (pw[i] * sum[one-1]);
        }
        else{//XOR
            res += llu (pw[i] * (one * zero));
        }
    }

    return res;
}
int main()
{
    pw[0] = 1;
    for(int i=1;i<=29;i++) pw[i] = pw[i-1] * 2;
    for(int i=1;i<mx;i++) sum[i] = i + sum[i-1];
    //cout<<sum[100000];
    //cout<<pw[30]<<" "<<sum[30]<<endl;
    //

    scii(n,q);
    int num;
    for(int i=1;i<=n;i++){
        sci(num);
        make_tree(num,i);
        ar[i] = num;
//        cout<<"ar "<<i<<" "<<ar[i]<<endl;
    }
//    for(int i=0;i<6;i++){
//        cout<<i<<" row: ";
//        for(int j=1;j<=10;j++) cout<<tree[j][i]<<" ";
//        cout<<endl;
//    }
    //cout<<tree[1][6].one<<" "<<tree[1][6].zero<<endl;
    int type,pos,l,r;
    llu ans = 0;

    while(q--){
        sci(type);
        if(type==1){
            scii(num,pos);
            make_tree(num,pos);
            //cout<<tree[1][6].one<<" "<<tree[1][6].zero<<endl;
        }
        else{
            //scanf(" %s",ch);
            cin>>ch;
            scii(l,r);

            if(l==r){
                printf("0\n");
                continue;
            }

            if(ch[0]=='O'){//or
                //cout<<"f"<<endl;
                ans = clc(l,r,1);
            }
            else if(ch[0]=='A'){//and
                ans = clc(l,r,2);
            }
            else{ //XOR
                ans = clc(l,r,3);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
