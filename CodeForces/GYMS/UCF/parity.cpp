#include<iostream>
#include<string>

using namespace std;

int nums[26];

int main(){
	string re;
	cin >> re;
	for(int i = 0; i < re.size();++i)
		++nums[re[i]-'a'];
	int pa,impa;
	pa = impa = 0;
	//for(int i = 0; i < 26;++i) printf("%d ",nums[i]);
	//puts("");
	for(int i = 0; i < 26;++i){
		if(nums[i]&1)
			++impa;
		else if(nums[i] != 0)
			++pa;
	}
	//cout << pa << endl;
	//cout << impa << endl;
	if(pa && !impa)
		puts("0");
	else if(!pa && impa)
		puts("1");
	else
		puts("2");
	return 0;
}