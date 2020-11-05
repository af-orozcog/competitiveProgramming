#include<bits/stdc++.h>
using namespace std;

char cards[56];
char bet[56];

map<char,int> as = {{'X',10},{'J',11},{'Q',12},{'K',13},{'A',14}};

struct cmp{
    bool operator()(char a, char b) const{
        return as[a] < as[b];
    }
};
bool comp2(char a, char b){
    return as[a] < as[b];
}

bool comp3(const pair<int,char> &a, const pair<int,char> &b){
    if(a.first < b.first) return true;
    else if(a.first > b.first) return false;
    return comp2(a.second,b.second);
}

int main(){
    for(int i = 1; i<=9; ++i)as[i+'0']=i;
    int n,k;
    scanf(" %d %d",&n,&k);
    scanf(" %s %s",cards,bet);
    unordered_set<char> seenBefore;
    unordered_map<char,int> tr;
    set<char,cmp> notSeen = {'1','2','3','4','5','6','7','8','9','X','J','Q','K','A'};
    set<char,cmp> good;
    for(int i = 0;i < n;++i) {
        if (bet[i] == 'y' && !seenBefore.count(cards[i]))
            good.insert(cards[i]);
        if(bet[i] == 'n' && seenBefore.count(cards[i])){
            puts("impossible");
            return 0;
        }
        seenBefore.insert(cards[i]);
        notSeen.erase(cards[i]);
        ++tr[cards[i]];
    }
    if(good.size() > k){
        puts("impossible");
        return 0;
    }
    vector<char> answer;
    vector<pair<int,char>> select;
    int have = k-good.size();
    for(auto va:good){
        select.push_back({-(4-tr[va]-1),va});
        answer.push_back(va);
    }
    sort(select.begin(),select.end(),comp3);
    for(auto va:select){
        int to = -va.first;
        for(int i = 0; i < min(to,have);++i)
            answer.push_back(va.second);
        have -= min(have,to);
        if(!have) break;
    }
    for(auto va:notSeen){
        for(int i = 0; i < min(4,have);++i)
            answer.push_back(va);
        have -= min(4,have);
        if(!have) break;
    }
    sort(answer.begin(),answer.end(),comp2);
    if((int)answer.size() != k){
        puts("impossible");
        return 0;
    }
    for(auto va:answer)
        printf("%c",va);
    puts("");
    return 0;
}

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

int nums[MAX];

int toi(char c){
    if(c<='9') return c-'0'-2;
    if(c=='X') return 8;
    if(c=='J') return 9;
    if(c== 'Q') return 10;
    if(c=='K') return 11;
    if(c=='A') return 12;
}

char itoc(int n){
    if(n<8) return '0'+2+n;
    if(n==8) return 'X';
    if(n==9) return 'J';
    if(n==10) return 'Q';
    if(n==11) return 'K';
    if(n==12) return 'A';

}
int cnt[13];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.in", "r", stdin);

    set<int> noTiene;
    int t, n,k;

    cin>>n>>k;
    string s1, s2;
    cin>>s1>>s2;
    vector<int> mano;
    for(int i = 0; i<n; ++i){
        int ind = toi(s1[i]);
        if(s2[i]=='y'){

            if(cnt[ind]==0){
                cnt[ind]++;
                mano.pb(ind);
                --k;
            }

        }
        else {
            if(cnt[ind]>0){
                cout<<"impossible\n";
                return 0;
            }
            else{
                noTiene.insert(ind);
            }
        }
        cnt[ind]++;
    }
    if(k<0){
        cout<<"impossible\n";
        return 0;
    }
    priority_queue<pii> pq;
    for(int i = 0; i<13; ++i){
        pq.push({cnt[i], -i});
    }
    while(pq.size() && k>0){
        pii p = pq.top();
        pq.pop();
        if(noTiene.count(-p.ss)) continue;
        int d = min(k, 4-p.ff);
        while(d--){
            mano.pb(-p.ss);
            k--;
        }
    }
    if(k!=0){
         cout<<"impossible\n";
         return false;
    }
    sort(mano.begin(), mano.end());
    for(auto x: mano){
        cout<<itoc(x);
    }
    cout<<"\n";

}



