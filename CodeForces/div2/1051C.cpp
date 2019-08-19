#include<iostream>
#include<map>

using namespace std;

int main(){
	map<int,int> freq;
	int n;
	scanf(" %d",&n);
	int ar[n];
	for(int i = 0; i < n;++i){
		scanf(" %d",&ar[i]);
		if(freq.count(ar[i]))
			++freq[ar[i]];
		else
			freq[ar[i]] = 1;
	}
	map<int,short> unique;
	for(auto const &pa: freq){
		if(pa.second == 1)
			unique[pa.first] = 0;
	}
	if(unique.size()== 0){
		puts("YES");
		for(int i = 0; i < n;++i){
			printf("B");
		}
		puts("");
		return 0;
	}
	if(unique.size() % 2 == 1){
		int ava = freq.size()-unique.size();
		if(ava == 0){
			puts("NO");
			return 0;
		}
		for(auto const &pa: freq){
			if(pa.second > 2){
				unique[pa.first] = 0;
				break;
			}
		}
		if(unique.size() % 2 == 1){
			puts("NO");
			return 0;
		}
	}
	int on = 0;
	puts("YES");
	for(int i = 0; i < n;++i){
		if(unique.count(ar[i])){
			if(unique[ar[i]] == 0){
				unique[ar[i]] = on+1;
				cout << (on?'B':'A');
				on = on?0:1;
			}
			else
				cout << ((unique[ar[i]] == 1)?'B':'A');
		}
		else
			cout << 'B';
	}
	cout << endl;
	return 0;
}
