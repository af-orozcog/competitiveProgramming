#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+2;
int n;

struct lol{
    int bad;
    int still;
    int good;
    lol():bad{0},still{0},good{0}{};
    lol(int b, int s, int g): bad{b},still{s},good{g}{};
};

lol t[2*MAX];

lol combine(lol &left, lol &right){
    lol answer;
    int important = min(left.still,right.bad);
    answer.good = left.good + right.good + important*2;
    answer.still = left.still - important + right.still;
    answer.bad = left.bad + right.bad - important;
    return answer;
}

void build(){
    for(int i = n-1; i > 0;--i) t[i] = combine(t[i<<1],t[i<<1|1]);
}

lol query(int l, int r){
    lol left,right;
    for(l += n,r += n; l < r; l>>=1, r >>=1){
        if(l&1) left = combine(left,t[l++]);
        if(r&1) right = combine(t[--r],right);
    }
    return combine(left,right);
}


int main(){
    string see;
    cin >> see;
    n = see.size();
    for(int i = 0; i < n;++i){
        if(see[i] == ')')
            t[i+n] = lol(1,0,0);
        else t[i+n] = lol(0,1,0);
    }
    build();
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        lol temp = query(l-1,r);
        cout << temp.good << "\n";
    }
    return 0;
}
