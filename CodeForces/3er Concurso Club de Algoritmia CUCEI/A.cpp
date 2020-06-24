#include<bits/stdc++.h>
using namespace std;

int low(vector<string> &where, string &f){
    int lo = 0, hi = where.size()-1,ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        string comp = where[mid].substr(0,f.size());
        if(comp == f){
            ans = mid;
            hi = mid -1;
        }
        else if(comp > f) hi = mid -1;
        else lo = mid + 1;
    }
    return ans;
}

int hi(vector<string> &where, string &f){
    int lo = 0, hi = where.size()-1,ans = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        string comp = where[mid].substr(0,f.size());
        if(comp == f){
            ans = mid;
            lo = mid + 1;
        }
        else if(comp > f) hi = mid -1;
        else lo = mid + 1;
    }
    return ans;
}

int ar[1000007];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin >> n >> q;
    vector<string> words;
    while(n--){
        string add;
        cin >> add;
        words.push_back(add);
    }
    sort(words.begin(),words.end());
    while(q--){
        string look;
        cin >> look;
        int lo = low(words,look);
        int ri = hi(words,look);
        if(lo == -1)continue;
        else
            ar[lo] += 1,ar[ri+1] -= 1;
    }
    vector<string> ans;
    int sum = 0;
    for(int i = 0; i < words.size();++i){
        sum += ar[i];
        if(!sum) ans.push_back(words[i]);
    }
    cout << ans.size() << "\n";
    for(auto va:ans)
        cout << va << "\n";
    return 0;
}
