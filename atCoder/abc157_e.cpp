#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main(){
    int siz;
    scanf(" %d",&siz);
	string re;
	cin >> re;
	vector<set<int>> let(26);
	for(int i = 0; i < int(re.size());++i)
		let[re[i]-'a'].insert(i);

	int q;
	scanf(" %d",&q);
	while(q--){
		int t;
		scanf(" %d",&t);
		if(t == 1){
			int pl;
			scanf(" %d",&pl);
			--pl;
			char add;
			scanf(" %c",&add);
			let[re[pl] - 'a'].erase(pl);
			re[pl] = add;
			let[re[pl]-'a'].insert(pl);
		}
		else{
			int ans = 0;
			int l,r;
			scanf(" %d %d",&l,&r);
			--l,--r;
			for(int i = 0; i < 26;++i){
				auto it = let[i].lower_bound(l);
				if(it != let[i].end() && *it <= r) ++ans;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
