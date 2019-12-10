#include<bits/stdc++.h>
using namespace std;

int set_bit(int mask,int pos)
{
    return  mask | (1<<pos);
}
int clear_bit(int mask,int pos)
{
    return mask & ~(1<<pos);
}
int check_bit(int mask,int pos)
{
    return (bool) (mask & (1<<pos) );
}
int main()
{

}
