#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};
#define MAX 100007
#define ll long long int
#define llu unsigned ll
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

ll base[10],x[10],y[10];
int A,B;

void pre()
{
    int a,n=0;
    base[0] = 111;
    while(++n<1000){
        a = n;
        while(a>0){
            base[a%10]++;
            a/=10;
        }
    }
}
int main()
{

    pre();
    int n,a;
    while(scanf("%d %d", &A, &B) && A && B){
        mem(x,0);
        mem(y,0);
        if(A>B) swap(A,B);
        //part 1
        A--;
        if(A<999){
            n = 0;
            while(++n<=A){
                a = n;
                while(a>0){
                    x[a%10]++;
                    a/=10;
                }
            }
//            x[0] += A+1;
//            x[0] += A>10 ? 10 : A;
        }
        else{
            n = -1;
            while(1){
                if(n+1000<=A){
                    n += 1000;
                    for(int i=0;i<=9;i++) x[i] += base[i];
                    if(n<=999) x[0] -= 111;
                    //
                    a = n/1000;
                    if(n>999){
                        //cout<<a<<endl;
                        while(a>0){
                            x[a%10] += 1000;
                            a/=10;
                        }
                    }
                }
                else{

                    while(++n<=A){
                        a = n;
                        while(a>0){
                            x[a%10]++;
                            a/=10;
                        }
                    }
                    break;
                }
            }
        }
        // part 2
        A = B;
        if(A<999){
            n = 0;
            while(++n<=A){
                a = n;
                while(a>0){
                    y[a%10]++;
                    a/=10;
                }
            }
        }
        else{
            n = -1;
            while(1){
                if(n+1000<=A){
                    n += 1000;
                    for(int i=0;i<=9;i++) y[i] += base[i];
                    if(n<=999) y[0] -= 111;
                    //
                    a = n/1000;
                    if(n>999){
                        //cout<<a<<endl;
                        while(a>0){
                            y[a%10] += 1000;
                            a/=10;
                        }
                    }
                }
                else{

                    while(++n<=A){
                        a = n;
                        while(a>0){
                            y[a%10]++;
                            a/=10;
                        }
                    }
                    break;
                }
            }
        }
        //
        for(int i=0;i<=9;i++){
            if(i<9) printf("%lld ",y[i]-x[i]);
            else printf("%lld\n",y[i]-x[i]);
        }
    }
    return 0;
}
