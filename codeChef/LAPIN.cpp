#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		map<char,int> freq;
		string re;
		cin >> re;
		string pa1 = re.substr(0,re.size()>>1);
		int start = re.size()>>1;
		if(re.size() & 1)
			++start;
		string pa2 = re.substr(start,re.size()>>1);
		sort(pa1.begin(),pa1.end());
		sort(pa2.begin(),pa2.end());
		bool can = true;
		for(int i = 0; i< pa1.size() && can;++i){
			if(pa1[i] != pa2[i])
				can = false;
		}
		if(can)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}