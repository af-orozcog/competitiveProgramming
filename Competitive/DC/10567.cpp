#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<vector<int>> vvi;
vvi letters(52);
void sett(string let){
	for(int i = 0; i < let.size();++i){
		if(let[i] >= 97)
			letters[let[i]- 97 + 26].push_back(i);
		else
			letters[let[i] - 65].push_back(i);
	}
}

int main(){
	string can;
	cin >> can;
	sett(can);
	int que;
	cin >> que;
	while(que--){
		string val;
		cin >> val;
		int from;
		if(val[0] >= 97)
			from = val[0] - 97  + 26;
		else
			from = val[0] - 65;
		int first = -1;
		int last;
		int start = 0;
		int pos = 0;
		bool posi = true;
		while(pos < val.size()){
			vector<int> toSee;
			if(val[pos] >= 97)
				toSee = letters[val[pos] - 97 + 26];
			else
				toSee = letters[val[pos] - 65];
			vector<int>::iterator low = lower_bound(toSee.begin(),toSee.end(),start);
			if(low == toSee.end()){
				posi = false;
				break;
			}
			else{
				if(first == -1)
					first = toSee[low - toSee.begin()];
				last = low - toSee.begin();
				if(start == toSee[last] && last != toSee.size() -1 )
					last += 1;
				else if(start == toSee[last]){
					posi = false;
					break;
				}
				last = toSee[last];
				start = last;
			}
			++pos;
		}
		if(posi)
			cout << "Matched " << first << " " << last << endl;
		else
			cout << "Not matched" << endl;
	}
	return 0;
}