#include<bits/stdc++.h>

using namespace std;

int main()
{   vector <float> nums;
    int numStudents,loopVar1,pos;
    float amount,sum=0,roundAmt,ans;
    string strAns;
    stringstream ss;
    while(cin>>numStudents) {
        if(numStudents==0)
            break;
        ans=sum=0;
        nums.erase(nums.begin(),nums.end());
        for(loopVar1=0;loopVar1<numStudents;loopVar1++) {
            cin>>amount;
            nums.push_back(amount);
            sum+=amount;
        }
        sum/=numStudents;
        roundAmt=(int)(sum*100);
        cout<<roundAmt<<endl;
        roundAmt/=100.0f;
        cout<<roundAmt<<"\n";
        for(loopVar1=0;loopVar1<numStudents;loopVar1++)
            if(nums[loopVar1]<roundAmt)
                ans+=(roundAmt-nums[loopVar1]);

        strAns="";
        ss.str("");
        ss<<ans;
        strAns=ss.str();
        pos=strAns.find('.');
        if(pos==-1)
            strAns+=".00";
        else
            strAns.erase(pos+3);
        cout<<'$'<<strAns<<"\n";
    }

/*
int main()
{
    while(1)
    {
        long n;
        scanf("%ld",&n);
        if(n==0) break;

        double cost[n],value=0.0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&cost[i]);
            value+=cost[i];
        }

        double temp=value/n;

        temp*=1000;
        long num=(long) temp;
        cout<<temp<<" "<<num<<endl;





        //charstring s = to_string(temp);
        //string s = (string) temp; str[100];

        /*int l=s.length();
        for(int i=0;i<l;i++) str[i]=str[i];
        printf("%s",str);
        int j,a,b;
        for(int i=0;i<str.length();i++) if(str[i]=='.') j=i;

        if(str.length()>j+3){

            if(str[j+2] != '9'){
                if(str[j+3]>='5') str[j+2]+='1';
            }
        }*/




        //long temp= (long) value;
        //double t= value-temp;
        //string str;
        //str=(char) t;
        //cout<<str<<endl;
        //cout<<t<<" ";


        //cout<<avg<<endl;

       /* double amount=0.0;
        for(int i=0;i<n;i++)
            if(cost[i]>avg){

                amount+= (double) (long) ((cost[i] - avg) * 100.0) / 100.0;
            }

        cout.unsetf (ios::floatfield );
        cout.precision(2);*/

        //printf("$%.2lf\n",amount);


return 0;
}




