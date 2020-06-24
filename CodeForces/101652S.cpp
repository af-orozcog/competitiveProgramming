//#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)\
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")\
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100005
#define ff first
#define ss second
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int n;
string re;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> re;
    vector<int> op1(re.size(),0),op2(re.size(),0);
    for(int i = 0; i < re.size();++i){
        if(re[i] == 'B') op1[i] = 1,op2[i] = -1;
        else op1[i] = -1,op2[i] = 1;
    }
    int ans = 0;
    int left = -1;
    int leftA = 10000000,rightA;
    int temp = 0;
    for(int i = 0; i < re.size();++i){
        temp += op1[i];
        if(left == -1) left = i;
        if(temp < 0){
            temp = 0;
            left = -1;
        }
        if(temp > ans){
            ans = temp;
            leftA = left, rightA = i;
        }
    }
    left = -1;
    temp = 0;
    for(int i = 0; i < re.size();++i){
        temp += op2[i];
        if(left == -1) left = i;
        if(temp < 0){
            temp = 0;
            left = -1;
        }
        if(temp > ans){
            ans = temp;
            leftA = left,rightA = i;
        }
        else if(temp == ans && left < leftA || (left == leftA && i < rightA)){
            leftA = left, rightA = i;
        }
    }
    printf("%d %d\n",leftA+1,rightA+1);
    return 0;
}


