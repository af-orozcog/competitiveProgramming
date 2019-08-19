#include<iostream>
#include<vector>
#define ll long long
#include<cmath>

using namespace std;
vector<ll> answer;
vector<double> nums;
int com;

ll solve(ll sum, int taken){
	if(taken == com)
		return sum;

}


int main(){
	int siz;
	cin >> siz;
	com = siz;
	while(siz--){
		double val;
		cin >> val; 
		nums.push_back(val);
	}
}