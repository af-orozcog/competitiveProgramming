#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int k;
	cin >> k;
	vector<int> num(12);
	for(int i = 0; i < 12;++i){
		cin >> num[i];
	}
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	int sum = 0;
	int i = 0;
	for(; i < 12;++i){
		sum += num[i];
		if(sum >= k)
			break;
	}
	if(sum < k)
		puts("-1");
	else
		printf("%d\n",(k == 0 ? i : i +1));
	return 0;
}