#include<iostream>
#include<vector>

using namespace std;

int main(){
	bool fi = 0;
	while(1){
		int n;
		scanf(" %d",&n);
		if(fi)
			puts("");
		if(n == 0)
			break;
		fi = 1;
		while(1){
			int com[n];
			scanf(" %d",&com[0]);
			if(com[0] == 0)
				break;
			bool can = 0;
			for(int i = 1; i < n;++i)scanf(" %d",&com[i]);
			vector<int> help; 
			for(int i = 1,j = 0; i <= n;++i){
				help.push_back(i);
				while(help.size() && help.back() == com[j]){
					help.pop_back();
					++j;
				}
			}
			if(help.size())
				puts("No");
			else
				puts("Yes");
		}
	}
	return 0;
}