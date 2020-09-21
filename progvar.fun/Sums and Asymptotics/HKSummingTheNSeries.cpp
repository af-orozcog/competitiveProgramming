#include <bits/stdc++.h>

using namespace std;

long mod = 1000000007;
/*
 * Complete the summingSeries function below.
 */
int summingSeries(long n) {
    long temp = n-1;
    long answer = ((temp*2L) % mod) + ((temp%mod)*(temp%mod))+ 1L;
    answer %= mod;
    if(answer <  0) answer += mod;
    return answer;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = summingSeries(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
