#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	vector<int> odd;
	vector<int> even;
	for(int i = 0; i < n;++i){
		int val;
		scanf(" %d",&val);
		if(val & 1)
			odd.push_back(val);
		else
			even.push_back(val);
	}
	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());
	reverse(odd.begin(),odd.end());
	reverse(even.begin(),even.end());
	//cout << even.size() << endl;
	//cout << odd.size() << endl;
	int best = 0;
	for(int i = 0; i < even.size();++i){
		if(even[i]<0)
			break;
		else
			best += even[i];
	}
	//printf("%d\n",best);
	int big = -1000000000;
	int min = 1000000000;
	for(int i = 0; i < odd.size();++i){
		if(odd[i]< 0){
			big = odd[i];
			break;
		}
		else{
			min = odd[i];
			best += odd[i];
		}
	}
	//cout << best << endl;
	if((best & 1) == 0)
		best -= min < -big? min:-big;
	printf("%d\n",best);
	return 0;
}