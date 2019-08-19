#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> nums((100 <<2));

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		int n;
		scanf(" %d",&n);
		for(int i = 0; i < (n<<2);++i)
			scanf(" %d", &nums[i]);
		sort(nums.begin(),nums.begin()+(n<<2));
		int i = 0;
		int j = (n<<2) -1;
		int sum = (nums[0])*(nums[j]);
		if(nums[0] != nums[1] || (nums[j] != nums[j-1])){
			puts("NO");
			continue;
		}
		int po = 1;
		i += 2;
		j -= 2;
		while(i < j && po){
			if(nums[i] != nums[i+1] || nums[j] != nums[j-1])
				po = 0;
			int neSum = nums[i]*nums[j];
			if(neSum != sum)
				po = 0;
			i += 2;
			j -= 2;
		}
		if(po)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}