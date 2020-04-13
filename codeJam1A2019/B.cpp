#include<bits/stdc++.h>
using namespace std;
const int N = 20;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int testCases;
long long a[N], n[N], ans, lcm;
int main()
{
    int t,nr,mr;
    scanf(" %d %d %d",&t,&nr,&mr);
    while(t--){
        int ar[] = {0,11,13,15,17,18,7};
        for(int i = 1; i <= 6; ++i){
            for(int j = 0; j < 18;++j){
                printf("%d ",ar[i]);
            }
            puts("");
            fflush(stdout);
            int imp = 0;
            for(int j = 0; j < 18;++j){
                int va;scanf(" %d",&va);
                imp += va;
                if(imp >= ar[i]) imp -= ar[i];
            }
            a[i] = imp;
            n[i] = ar[i];
            normalize(a[i], n[i]);
        }
        ans = a[1];
        lcm = n[1];
        for(int i = 2; i <= 6; ++i)
        {
            auto pom = ex_GCD(lcm, n[i]);
            int x1 = pom.x;
            int d = pom.d;
            if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
            ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
            lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
        }
        printf("%lld\n",ans);
        fflush(stdout);
        int ans;
        scanf(" %d",&ans);
        if(ans == -1)return 0;
        //printf("wtf is T: %d\n",t);
    }
    return 0;
}
