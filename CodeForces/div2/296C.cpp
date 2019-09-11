/**
* I do this because of Valentina, she motivates me :)
*/
#include<iostream>
#include<vector>
#include<cstring>
#define ll long long

using namespace std;
typedef pair<int,int> vii;
typedef pair<vii,ll> viii;

ll nums[100002];
ll ope[100002];

void update(int pos,ll val,bool who){
	ll *where; 
	where = (nums + pos);
	if(who)
		where = (ope + pos);
	while(pos < 100002){
		*where = (*where) +val;
		int dig = (pos&(-pos));
		pos += dig;
		where = (nums +pos);
		if(who)
			where = (ope + pos);
		//cout << (pos) << endl;
	}
}

ll sum(int pos,bool who){
	ll sum = 0;
	while(pos){
		if(who)
			sum += ope[pos];
		else
			sum += nums[pos];
		int dig = (pos&(-pos));
		pos -= dig;
	}
	return sum;
}

int main(){
	memset(nums,0,sizeof(nums));
	memset(ope,0,sizeof(ope));
	int n,m,k;
	scanf(" %d %d %d",&n,&m,&k);
	int init[n+1];
	vector<viii> opera(m+1);
	for(int i = 1; i < n+1;++i) scanf(" %d",&init[i]);
	for(int i = 1; i < m+1;++i){
		int l,r;ll d;
		cin >> l >> r >> d;
		opera[i] = {{l,r},d};
	}
	while(k--){
		int l,r;
		scanf(" %d %d",&l,&r);
		update(l,1,1);
		update(r+1,-1,1);
	}
	for(int i = 1; i < m+1;++i){
		ll vale = sum(i,1);
		if(vale){
			update(opera[i].first.first,vale*opera[i].second,0);
			update(opera[i].first.second + 1,-(vale*opera[i].second),0);
		}
	}
	for(int i = 1; i < n+1;++i){
		if(i == 1)
			cout << init[i] + sum(i,0);
		else
			cout << " " << init[i] + sum(i,0);
	}
	cout << endl;
	return 0;
}