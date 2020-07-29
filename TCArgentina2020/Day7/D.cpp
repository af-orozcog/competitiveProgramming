#include<bits/stdc++.h>
using namespace std;

static int power(int x, int y, int p)
    {
        // Initialize result
        int res = 1;

        // Update x if it is more
        // than or equal to p
        x = x % p;

       if (x == 0) return 0; // In case x is divisible by p;

        while (y > 0)
        {
            // If y is odd, multiply x
            // with result
            if((y & 1)==1)
                res = (res * x) % p;

            // y must be even now
            // y = y / 2
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }


int main(){
    int a,b;
    scanf(" %d %d",&a,&b);
    int ans = power(a,b,9);
    if(ans == 0) ans = 9;
    printf("%d\n",ans);
    return 0;
}
