#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>
#define ll long long

using namespace std;

bool order(pair<string,vector<ll>> a, pair<string,vector<ll>> b){
	return a.first < b.first;
}

ll direction(vector<ll> data1, vector<ll>data2){
	//cout << "data1 " << data1.size() << endl;
	ll base = data1[0];
	ll sizeByter = data1[1];
	ll dimensions = data1[2];
	vector<ll> Cs;
	Cs.push_back(sizeByter);
	int index = 0;
	for(int i = (dimensions*2) + 2;i > 4; i-=2){
		ll operations = data1[i] - data1[i-1] + 1;
		//cout << operations << endl;
	//	cout << "upper: " << data1[i];
	//	cout << " lower: " << data1[i-1] << endl;; 
		ll loans = operations * Cs[index++];
		Cs.push_back(loans); 
	}
	//cout << "Cs tiene" << endl;
	/*for(int i = 0; i < Cs.size(); i++){
		cout << Cs[i] << endl;
	}*/
	ll total = 0;
	index = 0; 
	for(int i = (dimensions*2) + 2; i > 2; i-=2){
		total -= Cs[index++]*data1[i-1];
	}
	//cout << "total es "<< total << endl; 
	ll C0 = base + total;
	ll answer = C0;
	index = Cs.size() - 1;
	//cout << "el tamaño de Cs es:" << Cs.size() << endl;
	for(int i = 0;i< Cs.size(); i++){
		answer += Cs[i]*data2[index--];
	//	cout << answer << endl;
	}
	return answer;
}

int main(){
	ll arr,refe;
	cin >> arr >> refe;
	vector<pair<string,vector<ll>>> arra;
	for(ll i = 0; i < arr; i++){
		string name;
		cin >> name;
		ll baseA;
		cin >> baseA;
		ll byt;
		cin >> byt;
		ll dimen;
		cin >> dimen;
		//cout << dimen << endl;
		vector<ll> toAdd;
		toAdd.push_back(baseA);
		toAdd.push_back(byt);
		toAdd.push_back(dimen);
		for(int j = 0; j < dimen*2;j++){
			ll val;
			cin >> val;
			toAdd.push_back(val);
		}
		//cout << "entro aqui"<<endl;
		pair<string,vector<ll>> add;
		add.first = name;
		add.second = toAdd;
		arra.push_back(add);
	}
	sort (arra.begin(), arra.end(), order);
	/*for(int i = 0; i < arr; i++){
		cout << arra[i].first << endl;
	}*/
	for(ll i = 0; i < refe; i++){
		string name;
		cin >> name;
		vector<pair<string,vector<ll>>>::iterator low;
		vector<ll> em;
		pair<string,vector<ll>> looked;
		looked.first = name;
		looked.second = em;
		low = lower_bound(arra.begin(),arra.end(),looked,order);
		//cout << low-arra.begin() << endl;
		pair<string,vector<ll>> toCheck = arra[(low-arra.begin())];
		vector<ll> toSee = toCheck.second;
	//	cout << "el tamaño de ToSee es: "<< toSee.size() << endl;
		vector<ll> vals;
		for(int i = 0; i < toSee[2];i++){
			ll val;
			cin >> val;
			vals.push_back(val);
		}
		ll direc = direction(toSee,vals);
		cout << name << "[";
		for(int i = 0; i < vals.size();i++){
			if(i == vals.size() - 1)
				cout << vals[i] << "] = ";
			else
				cout << vals[i]<<", ";
		}
		cout << direc << endl;
	}
	return 0;
}