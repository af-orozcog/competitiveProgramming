#include<iostream>
#include<vector>
#define max(x,y)(x > y? x:y)

using namespace std;

int main(){
	int cas;
	cin >> cas;
	int r = 0;
	while(cas--){
		++r;
		int siz;
		cin >> siz;
		int max = (1 << 31);
		int sum = 0;
		int first = 0;
		int last = 0;
		vector<int> nums(siz - 1);
		for(int i = 0; i < siz - 1;++i){
			int val;
			cin >> val;
			nums[i] = val;
			sum += val;
			if(sum > max){
				max = sum;
				last = i;
			}
			if(sum < 0){
				sum = 0;
				first = i + 1;
			}
		}
		if(max<0){
			cout << "Route " << r << " has no nice parts\n";
		}
		first = 0;
		last = -1;
		int tempFirst;
		sum = 0;
		for(int i = 0; i < siz -1;++i){
			sum += nums[i];
			if(sum == max){
				if(last == -1){
					last = i + 1;
					cout << last << endl;
					tempFirst = last;
				}
				else{
					if(i - tempFirst > last - first){
						first = tempFirst;
						last = i + 1;
					}
				}
			}
			if(sum < 0){
				sum = 0;
				if(last == -1)
					first = i + 1;
				else
					tempFirst = i + 1;
			}
		}
		cout << "The nicest part of route " << r <<" is between stops " << first + 1 << " and " << last + 1 << endl; 
	}
	return 0;
}