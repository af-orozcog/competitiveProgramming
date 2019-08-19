/**
* I'm sorry I was an idiot
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool com(const int a, const int b){
	return a > b;
}

int solve(vector<int> times, int sum, int in, int max){
	if(max - sum > 0){
		if(sum + times[in] <= max)
			return 0;
	}
	//cout << endl;
	int ans = 0;
	for(int i = 0; i < in;++i){
		//cout << times[i] << endl;
		sum -= times[i];
		++ans;
		if(sum + times[in] <= max)
			break;
	}
	return ans;
}

int main(){
	int N,M;
	cin >> N >>M;
	vector<int> stud(N);
	vector<int> sums(N);
	int total = 0;
	for(int i = 0; i < N;++i){
		cin >> stud[i];
		total += stud[i];
		//cout << total << endl;
		sums[i] = total;
	}
	vector<int> copy = stud;
	for(int i = 0; i < N;++i){
		if(i == 0){
			cout << 0;
		}
		else{
			sort(stud.begin(),stud.begin() + i,com);
			//cout << "sums " <<sums[i-1] << endl;
			cout << " " << solve(stud,sums[i-1],i,M);
		}
		stud = copy;
	}
	cout << endl;
	return 0;
}