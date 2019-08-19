#include<iostream>
#include<map>
#define ll long long

using namespace std;

int main(){
	int que;
	cin >> que;
	while(que--){
		map<ll,int> vals;
		int n;
		cin >> n;
		ll max = 0;
		int threes = 0;
		for(int i = 0; i < n;++i){
			ll ne;
			cin >> ne;
			if(ne % 3 != 0){
				if(vals.count(ne) > 0)
					vals[ne]++;
				else
					vals[ne] = 1;
				if(ne > max)
					max = ne;
			}
			else
				++threes;
		}
		while(true){
			int op = 0;
			for(auto const &pa : vals){
				ll val = 1;
				if(pa.first == 1)
					continue;
				while(vals[pa.first] != 0 && pa.first * val * 2 <= max){
					if(vals.count(pa.first*val*2) > 0){
						if(vals[pa.first] < vals[pa.first*val*2]){
							vals[pa.first*val*2] -= pa.second;
							op += pa.second;
							vals[pa.first] = 0;
						}
						else{
							vals[pa.first] -= vals[pa.first*val*2];
							op += vals[pa.first*val*2];
							vals[pa.first*val*2] = 0;
						}
					}
					val += 2;
				}
			}
			if(op == 0)
				break;
			threes += op;
		}
		if(vals.count(1) > 0){
			for(auto const &pa : vals){
				if(vals[pa.first] != 0 && (pa.first + 1) % 3 == 0){
					if(vals[pa.first] < vals[1]){
						threes += pa.second;
						vals[1] -= pa.second;
						vals[pa.first] = 0;
					}
					else{
						threes += vals[1];
						vals[pa.first] -= vals[1];
						vals[1] = 0;
					}
				}
			}
		}
		cout << "antes de los 1 solos " << threes << endl;
		for(auto const &pa : vals){
			if(pa.second != 0){
				threes += pa.second / 3;
			}
		}
		cout << threes << endl;
	}
	return 0;
}