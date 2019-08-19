#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string n,m;
	cin >> n >>m;
	reverse(n.begin(),n.end());
	cout << (n.compare(m) == 0? "YES":"NO") << "\n";
	return 0;
}