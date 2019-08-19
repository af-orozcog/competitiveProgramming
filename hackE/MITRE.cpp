#include<iostream>
#include<map>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int e;
		cin >> e;
		map<int,bool> unique;
		while(e--){
			int a,b;
			cin >> a >> b;
			unique[a] = true;
			unique[b] = true;
		}
		cout << unique.size() << endl;
	}
}