#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;

#define MAXN   10001
int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int power(int x, int y)
{
    int res = 1;     // Initialize result

    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        // y must be even now
        y = y>>1; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
}

int main(){
    sieve();
    int t;
    scanf(" %d",&t);
    while(t--){
        int n,m;
        scanf(" %d %d",&n,&m);
        unordered_map<int,int> fr;
        for(int i = 0; i < n;++i){
            int va; scanf(" %d",&va);
            unordered_map<int,int> tempFr;
            vector<int> primeF = getFactorization(va);
            for(auto va: primeF)
                ++tempFr[va];
            for(auto va:tempFr)
                fr[va.first] = max(fr[va.first],va.second);
        }
        int ma = 1;
        int who = 1;
        for(int i = 1; i <= m;++i){
            unordered_map<int,int> tempFr;
            vector<int> primeF = getFactorization(i);
            for(auto va: primeF)
                ++tempFr[va];
            int va1 = 1;
            for(auto va:tempFr)
                va1 *= power(va.first,max(va.second - fr[va.first],0));
            if(va1 > ma) ma = va1, who = i;
        }
        //cout << ma << endl;
        printf("%d\n",who);
    }
    return 0;
}
