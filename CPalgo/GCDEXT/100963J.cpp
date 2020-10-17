#include <iostream>
#include<string>
#include<math.h>
using namespace std;
long long int gcd( long long int a,long long  int b,long long int &x,long long int &y)
{
    if(a==0)
    {
        x=0;y=1;
        return b;
    }
    long long  int x1,y1,z;
    z=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return z;

}
int main()
{
    long long int n,m,a,k,x,y,d;
    while(cin>>n>>m>>a>>k)
    {
        if(n+m+a+k==0 ) break;
        d=gcd(m,a,x,y);
        if((k+a-n)%d!=0) { cout<<"Impossible\n"; continue;}
        x=x*(k+a-n)/d;
        x=x%(a/d);
        while(m*x<(k+a-n) || x <0) x+=a/d;
        cout<<n+m*x<<"\n";
    }
    return 0;
}
