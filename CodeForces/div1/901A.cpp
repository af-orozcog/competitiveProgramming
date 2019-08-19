#include<iostream>
#include<vector>

using namespace std;

int main(){
	int h;
	cin >> h;
	int n[h+1];
	bool pe = true;
	int sum = 0;
	int f = 1;
	for(int i = 0; i < h+1;++i){
		int va;
		cin >> va;
		sum += va;
		if(f != 1 && va != 1)
			pe = false;
		n[i] = va;
		f = va;
	}
	if(pe){
		cout << "perfect\n";
		return 0;
	}
	vector<int> an1;
	vector<int> an2;
	an1.push_back(0);
	an2.push_back(0);
	int last = 1;
	bool change = false;
	for(int i = 1; i <= h;++i){
		int le = last;
		for(int j = 0; j < n[i];++j){
			if(!change && n[i-1] >= 2 && n[i] > 1){
				an2.push_back(le-1);
				change = true;
			}
			else
				an2.push_back(le);
			an1.push_back(le);
			++last;
		}
	}
	cout << "ambiguous\n";
	for(int i = 0; i < an1.size();++i){
		if(i == 0)
			cout << an1[i];
		else
			cout << " "<< an1[i];
	}
	cout << endl; 
	for(int i = 0; i < an1.size();++i){
		if(i == 0)
			cout << an2[i];
		else
			cout << " "<< an2[i];
	}
	cout << endl;
	return 0;
}