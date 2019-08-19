/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<deque>
#include<vector>
#define ll long long

using namespace std;

vector<int> power;
ll simulation(deque<int> nums, int max){
	ll total = 1;
	while(true){
		int val1 = nums.front();
		nums.pop_front();
		int val2 = nums.front();
		nums.pop_front();
		if(val1 <= val2){
			int temp = val1;
			val1 = val2;
			val2 = temp;
		}
		nums.push_front(val1);
		nums.push_back(val2);
		++total;
		if(val1 == max)
			break;
	}
	int siz = nums.size();
	for(int i = 0; i < siz;++i){
		int val1 = nums.front();
		//cout << val1<< endl; 
		if(i != 0)
			power.push_back(val1);
		nums.pop_front();
	}
	return total;
}

int main(){
	int siz,que;
	cin >> siz >> que;
	deque<int> nums;
	deque<int> copy;
	int max = -1;
	for(int i = 0; i < siz;++i){
		int val;
		cin >> val;
		nums.push_back(val);
		if(val > max)
			max = val;
	}
	copy = nums;
	ll imp = simulation(nums,max);
	//cout << "imp es: " << imp << endl;
	while(que--){
		ll upTo;
		cin >> upTo;
		ll cpy = upTo;
		if(upTo >= imp){
			ll start = upTo - imp;
			start = start % power.size();
			//cout << "start " << start << endl;
			cout << max << " " << power[start] << endl;
			continue;
		}
		nums = copy;
		for(ll i = 0; i < upTo - 1;++i){
			int val1 = nums.front();
			nums.pop_front();
			int val2 = nums.front();
			nums.pop_front();
			if(val1 <= val2){
				int temp = val1;
				val1 = val2;
				val2 = temp;
			}
			nums.push_front(val1);
			nums.push_back(val2);
		}
		int val1 = nums.front();
		nums.pop_front();
		int val2 = nums.front();
		nums.pop_front();
		cout << val1 << " " << val2 << endl;;
		if(val1 <= val2){
			int temp = val1;
			val1 = val2;
			val2 = temp;
		}
		nums.push_front(val1);
		nums.push_back(val2);
	}
	return 0;
}