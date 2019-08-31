/**
* I'm completely blocked
*/
#include<iostream>
#include<string>

using namespace std;

int main(){
	string re;
	cin >> re;
	int ones = 0;
	int last = -1;
	for(int i = 0;i < re.size();++i){
		if(re[i] == '1'){
			if(last == -1)
				last = i;
			++ones;
		}
	}
	if(last == -1)
		puts("0");
	else{
		//cout << last << endl;
		last = ((int)re.size()-1)-last;
		//cout << last << endl;
		int div = last >>1;
		--ones;
		int ans = div;
		if(last %2 == 1 || ones > 0)
			++ans;
		printf("%d\n",ans); 
	}
	return 0;
}