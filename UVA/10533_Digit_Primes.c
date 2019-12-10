#include<stdio.h>
#include<math.h>
#define N 1000000

int a[1000000]={0};

void seive()
{
     long i,j,x;

    long s=sqrt(N);

     for(i=4;i<=N;i+=2)
          a[i]=1;

     for(i=3;i<=s;i+=2)
     {
         if(a[i] == 0)
         {
             for(j=i*i;j<=N;j+=i)
                a[j]=1;
         }
     }
     a[1]=1;
     a[2]=0;
     a[0]=1;
}
long sum(long i){

   long s=0,x=0;
    while(i>0){

        x=i%10;
        i/=10;
        s+=x;
        x=0;
    }

return s;
}


int main()
{
    long n,num,t,c,i;
    seive();

    scanf("%ld",&t);
    while(t--){
    	c=0;
    	scanf("%ld %ld",&n,&num);

    	if(n%2==0)
            n++;

    	for(i=n;i<=num;i+=2)
    	{
    		 if(a[i]==0 ){

                if(a[sum(i)]==0)
                  c++;
            }

    	}
    	printf("%ld\n",c);

    }

return 0;
}
