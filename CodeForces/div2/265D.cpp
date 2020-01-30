#include<bits/stdc++.h>
using namespace std;

#define MAXN   100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
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

int dp[100001];
int ans = 1;

void fact(int x)
{
    set<int> ret;
    int temp = 0;
    while (x != 1)
    {
        ret.insert(spf[x]);
        temp  = max(dp[spf[x]]+1,temp);
        x = x / spf[x];
    }
    for(auto va: ret) dp[va] = temp;
    ans = max(temp,ans);
}

int main(){
    int n;
    scanf(" %d",&n);
    sieve();
    while(n--){
        int re;
        scanf(" %d",&re);
        fact(re);
    }
    printf("%d\n",ans);
    return 0;
}
