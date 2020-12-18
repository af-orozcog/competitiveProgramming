#include<bits/stdc++.h>
#define ll long long
using namespace std;

bitset<20000000> posi;
vector<int> p;
vector<int> digits;
vector<int> ones;


pair<int,int> counter(int val){
    int digits = 0;
    int ones = 0;
    while(val){
        if(val&1) ++ones;
        ++digits;
        val >>= 1;
    }
    return {digits,ones};
}

int numOnes(int val, int upTo){
    string use = "";
    while(val){
        if(val&1)use += "1";
        else use += "0";
        val >>=1;
    }
    reverse(use.begin(),use.end());
    int ans = 0;
    for(int i = 0; i < upTo;++i)
        ans += (use[i] == '1');
    return ans;
}

void count_primes(int n) {
    const int S = 10000000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i]){
                p.push_back(i+start);
                pair<int,int> imp = counter(i+start);
                imp.first += digits.back();
                imp.second += ones.back();
                digits.push_back(imp.first);
                ones.push_back(imp.second);
            }
        }
    }
}


int main(){
    p.push_back(0);
    digits.push_back(0);
    ones.push_back(0);
    count_primes(103000000);
    int t;
    scanf(" %d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int index = lower_bound(digits.begin(),digits.end(),n)-digits.begin();
        if(digits[index] == n)
            printf("%d\n",ones[index]);
        else{
            n-=digits[index-1];
            printf("%d\n",numOnes(p[index],n)+ones[index-1]);
        }
    }
    return 0;
}
