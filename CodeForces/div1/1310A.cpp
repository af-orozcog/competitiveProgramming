#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,int> pi;

int main(){
	int n;
	scanf(" %d",&n);
	map<int,vector<ll>> fr;
	pi nums[n];
	for(int i = 0;i < n;++i) scanf(" %d", &nums[i].first);
	for(int i = 0;i < n;++i) scanf(" %lld", &nums[i].second);
	for(int i = 0;i < n;++i)
		fr[nums[i].first].push_back(nums[i].second);
	vector<int> dist;
	int last = -1;
	for(auto it = fr.begin();it !=fr.end();++it){
		if(last != -1)
			dist.push_back((*it).first - last -1);
		last = (*it).first;
	}
	ll ans = 0;
	priority_queue<pi> q;
	int i = 0;
	int where = 0;
	for(auto &va:fr){
	    where = va.first;
        for(auto &ve: va.second)
            q.push({ve,-va.first});
        ans += q.top().first*(ll)(where + q.top().second);
        q.pop();
        ++where;
        for(int j = 0;i < dist.size() && j < dist[i] && q.size();++j,++where){
            ans += q.top().first*(ll)(where + q.top().second);
            q.pop();
        }
        ++i;
	}
	while(q.size()){
	    ans += q.top().first*(ll)(where + q.top().second);
        q.pop();
        ++where;
	}
	printf("%lld\n",ans);
    return 0;
}
