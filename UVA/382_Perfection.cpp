    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        cout<<"PERFECTION OUTPUT"<<endl;
        while(1)
        {
            int num;
            scanf("%d",&num);
            if(num==0) break;

            int sum=0;
            if(num>1) sum=1;
            for(int i=2;i*i<=num;i++)
            {
                if(num%i==0){
                    int x= num/i;
                    if(x!=i) sum+=x;
                    sum+=i;
                }
            }

            if(num==sum) printf("%5d  PERFECT\n",num);
            else if(sum>num) printf("%5d  ABUNDANT\n",num);
            else printf("%5d  DEFICIENT\n",num);

        }

        cout<<"END OF OUTPUT"<<endl;

    return 0;
    }
