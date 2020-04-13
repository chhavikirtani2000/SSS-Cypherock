#include <iostream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
using namespace std;
long long D[4];
long long regenerate()
{
    long long y0=D[0];
    long long y1=D[1];
    return 2*y0 - y1;
}
void generate_shares(long long secret[32])
{
    srand(time(NULL));
    long long s=32;
    long long number=0;
    for(long long i=0;i<s;i++)
    {
        number=number+secret[i]*(pow(10,(s-i-1)));
    }
    long long n=4;
    int num1 = rand()%(256 + 1); 
    int num2 = rand()%(256 + 1);
    int first,second;
    if(num1>num2)
    {
        first=num1;
        second=num2;
    }
    else
    {
        first=num2;
        second=num1;
    }
    if(first==0)
        first++;
    if(second==0)
        second++;
    for(long long x=1;x<=n;x++)
    {
        long long temp=(second*(pow(x,2)));
        D[x-1]=number + (first*x) + temp;
    }
}
int main()
{
    int s=32;
    long long secret[s]; //input the array
    for(long long i=0;i<s;i++)
    {
        long long a;
        cin>>a;
        secret[i]=a;
    }
    generate_shares(secret); //function to generate the shares
    cout<<regenerate(); //function to regenerate the secret from shares
    return 0;
}