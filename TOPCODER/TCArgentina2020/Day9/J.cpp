#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,char> pi;

ll ans(vector<pi> &see, int siz){
    ll coun = 0;
    vector<int> kmp(see.size(),0);
    int border = 0;
    for(int i = 1; i < see.size();++i){
        while(border > 0 && (see[i].second != see[border].second || (see[i].first != see[border].first && border != siz-1) || (see[i].first < see[border].first && (border == siz-1 || border == 0))))
            border = kmp[border-1];
        if(see[i].second == see[border].second){
            if(border == 0 && see[i].first >= see[border].first)
                ++border;
            else if(border == siz-1 && see[i].first >= see[border].first)
                ++border;
            else if(see[i].first == see[border].first)
                ++border;
            else
                border = 0;
        }
        else
            border = 0;
        if(border == siz){
            ++coun;
            --border;
            while(border > 0 && (see[i].second != see[border].second || (see[i].first != see[border].first)))
                border = kmp[border-1];
            if(see[i].second == see[border].second){
                if(border == 0 && see[i].first >= see[border].first)
                    ++border;
                else if(border == siz-1 && see[i].first >= see[border].first)
                    ++border;
                else if(see[i].first == see[border].first)
                    ++border;
                else
                    border = 0;
            }
            else
                border = 0;
        }
        kmp[i] = border;
    }
    return coun;
}


int main(){
    int n,m;
    scanf(" %d %d",&n,&m);
    vector<pi> a;
    vector<pi> b;
    for(int i = 0; i < n;++i){
        ll num;char let;
        scanf(" %lld-%c",&num,&let);
        if(a.size() && a.back().second == let)
            a.back().first += num;
        else
            a.push_back({num,let});
    }
    for(int i = 0; i < m;++i){
        ll num;char let;
        scanf(" %lld-%c",&num,&let);
        if(b.size() && b.back().second == let)
            b.back().first += num;
        else
            b.push_back({num,let});
    }
    if((int)b.size() == 1){
        ll anss = 0;
        for(auto &va:a)
            if(va.second == b[0].second && va.first >= b[0].first)
                anss += va.first-b[0].first+1ll;
        printf("%lld\n",anss);
        return 0;
    }
    vector<pi> send = b;
    send.push_back({0ll,'$'});
    for(auto va:a)
        send.push_back(va);
    printf("%lld\n",ans(send,(int)b.size()));
    return 0;
}
