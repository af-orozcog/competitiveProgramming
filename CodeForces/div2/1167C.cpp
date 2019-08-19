/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<map>

using namespace std;

int people[500000];
int weg[500000];
int weg2[500000];

int find(int look){
	return (people[look] == look) ? look : (people[look] = find(people[look]));
}

bool connected(int a ,int b){
	return find(a) == find(b);
}

void connect(int a, int b){
	int dadA = find(a),dadB = find(b);
	if(dadA != dadB){
		if(weg[dadA] > weg[dadB]){
			people[dadB] = dadA;
			weg2[dadA] += weg2[dadB];
		}
		else{
			people[dadA] = dadB;
			weg2[dadB]+= weg2[dadA];
			if(weg[dadA] == weg[dadB]){
				++weg[dadB];
			}
		}
	}
}

int main(){
	int peop,groups;
	cin >> peop >> groups;
	for(int i = 0; i < peop;++i){
		people[i] = i;
		weg[i] = 1;
		weg2[i] = 1;
	}
	while(groups--){
		int siz;
		cin >> siz;
		if(siz == 0)
			continue;
		int first;
		cin >> first;
		--first;
		for(int i = 1; i < siz;++i){
			int val;
			cin >> val;
			--val;
			if(!connected(first,val))
				connect(first,val);
		}
	}
	for(int i = 0;i < peop;++i){
		int dad = find(i);
		if(i == 0)
			cout << weg2[dad];
		else
			cout << " " << weg2[dad];
	}
	cout << endl;
	return 0;
}