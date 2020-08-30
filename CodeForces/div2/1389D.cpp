#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> pi;


ll leng(pi a){
    return a.second-a.first;
}

bool eq(pi a, pi b){
    return a.first == b.first && a.second == b.second;
}

pi uni(pi a, pi b){
    return {min(a.first,b.first),max(a.second,b.second)};
}

bool intersect(pi a, pi b){
    if(a.first <= b.second && a.first >= b.first) return 1;
    if(b.first <= a.second && b.first >= a.first) return 1;
    return 0;
}

ll intersection(pi a, pi b){
    pi see = {max(a.first,b.first),min(a.second,b.second)};
    return leng(see);
}

ll cost(pi a,pi b){
    return max(a.first,b.first)-min(a.first,b.first) + max(a.second,b.second) - min(a.second,b.second);
}

int main(){
    int t;
    scanf(" %d",&t);
    while(t--){
        int n; ll k;
        scanf(" %d %lld",&n,&k);
        pi nums1[n];
        pi nums2[n];
        for(int i = 0; i < n;++i)
            scanf(" %lld %lld",&nums1[i].first,&nums1[i].second);
        for(int i = 0; i < n;++i)
            scanf(" %lld %lld",&nums2[i].first,&nums2[i].second);
        ll ans = 0;
        ll temp = 0;
        for(int i = 0; i < n;++i){
            if(intersect(nums1[i],nums2[i]))
                temp += intersection(nums1[i],nums2[i]);
        }
        if(temp >= k) k = 0;
        vector<pi> toUse;
        for(int i = 0; i < n && k;++i){
            if(eq(num1[i],nums2[i]))
                k -= min(intersection(nums1[i],nums2[i]),k);
            else if(intersect(nums1[i],nums2[i])){
                pi see = uni(nums1[i],nums2[i]);
                ll cos = cost(nums1[i],nums2[i]);
                ll le = leng(see);
                ll les = min(le,k);
                k -= les;
                ans + = cos;
                nums1[i] = nums2[i] = see;
            }
            else{
                if(nums1[i].first < nums2[i].first)
                    toUse.push_back({nums2[i].first-nums1[i].second,i});
                else toUse.push_back({nums1[i].first-nums2[i].second,i})
            }
        }
        sort(toUse.begin(),toUse.end());
        for(int i = 0; i < toUse.size() && k;++i){
            if(leng(nums1[i]) > leng(nums2[i])){
                if(nums1[i].first < nums2[i].first)
                    nums2[i].first = nums1[i].first;
                else
                    nums2[i].second = nums1[i].second;
            }
            else{
                if(nums1[i].first < nums2[i].first)
                    nums1[i].second = nums2[i].second;
                else
                    nums1[i].first = nums2[i].first;
            }
        }
        for(int i = 0; i < n && k;++i){
            if(eq(num1[i],nums2[i])) continue;
            pi see = uni(nums1[i],nums2[i]);
            ll cos = cost(nums1[i],nums2[i]);
            ll le = leng(see);
            ll les = min(le,k);
            k -= les;
            ans + = cos;
        }
        if(k)
            ans += k<<1;
        printf("%lld\n",ans);
    }
    return 0;
}
