#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

int main(){
	int n,k,p;
	cin >> n >> k >> p;
	vector<int> people(n);
	for(int i = 0;i < n;++i){
		cin >> people[i];
	}
	sort(people.begin(),people.end());
	vector<int> keys(k);
	for(int i = 0; i < k;++i){
		cin >> keys[i];
	}
	sort(keys.begin(),keys.end());
	int ans = INT_MAX;
	for(int j = 0; j < k - n + 1;++j){
		int index = j;
		int mk = 0;
		for(int i = 0;i < n;++i){
			int check = abs(keys[index] - people[i]);
			check += abs(keys[index] - p);
			mk = max(mk,check);
			++index;
		}
		ans = min(ans,mk);
	}
	cout << ans << endl;
	return 0;
}