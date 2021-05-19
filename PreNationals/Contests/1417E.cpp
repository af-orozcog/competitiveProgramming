#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> trie;
vector<vector<int>> vals;

void ins(int num, int index){
    int start = 0;
    for(int i = 30; i > -1;--i){
        int val = (1<<i)&num;
        if(trie[start][val] == -1){
            trie[start][val] = trie.size();
            vector<int> add1(2,-1);
            vector<int> add2;
            trie.push_back(add1);
            vals.push_back(add2);
        }
        vals[start].push_back(index);
        start = trie[start][val];
    }
    vals[start].push_back(index);
}
ll ans[31][2];


void calc(int start, int pos = 30){
    vector<int> left = vals[trie[start][0]];
    vector<int> right = vals[trie[start][1]];
    ll see = 0;
    for(ll i = right.size()-1, j = left.size()-1;i > -1;--i){
        while(j > -1 && left[j] > right[i]){
            --j;
        }
        see += (ll)left.size()-1-j;
    }
    ans[pos][0] += see;
    see = 0;
    for(ll i = left.size()-1, j = right.size()-1; i > -1; --i){
        while(j > -1 && right[j] > left[i]){
            --j;
        }
        see += (ll)left.size()-1-j;
    }
    ans[pos][1] += see;
    calc(trie[start][0],pos-1);
    calc(trie[start][1],pos-1);
}

int main(){
    int n;
    trie.resize(1,vector<int>(2,-1));
    vals.resize(1);
    scanf(" %d",&n);
    for(int i = 0; i < n;++i){
        int va; scanf(" %d",&n);
        ins(va,i);
    }
    calc(0);
    int def = 0;
    ll amount = 0;
    for(int i = 0,j = 1; i < 31;++i,j<<=1){
        if(ans[i][1] > ans[i][0]){
            amount += ans[i][1];
            def = def | j;
        }
        else amount += ans[i][0];
    }
    printf("%d %lld\n",def,amount);
    return 0;
}
