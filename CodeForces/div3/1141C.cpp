#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int nums[n];
	int sum = 0;
	for(int i = 0; i < n-1;++i){
		int va;
		scanf(" %d",&va);
		sum += va;
		nums[i] = va;
	}
	vector<int> ans;
	for(int i = n; i > 0;--i){
		map<int,bool> co;
		int de = 0;
		int first = i - sum;
		//cout << first << " "<<i <<endl;
		if(first <= 0 || first > n)
			continue;
		de++;
		co[first] = true;
		ans.push_back(first);
		for(int j = 0; j < n-2;++j){
			int ve = nums[j] + first;
			//cout <<"here? "<< ve << endl;
			if(ve <= 0 || ve > n)
				break;
			if(co.count(ve) == 0){
				//cout << " ve is "<<ve << endl;
				co[ve] = true;
				++de;
			}
			else if(co.count(ve))
				break;
			first = ve;
			ans.push_back(first);
		}
		if(co.count(i) == 0){
			//cout << "inin" << endl;
			++de;
		}
		//cout << "de es " << de << endl;
		ans.push_back(i);
		if(de == n)
			break;
		ans.clear();
	}
	if(ans.size() != n){
		puts("-1");
		return 0;
	}
	for(int i = 0; i < ans.size();++i){
		if(i == 0)
			cout << ans[i];
		else
			cout << " "<<ans[i];
	}
	cout << endl;
}